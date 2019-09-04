// ============================================================================
// Copyright (c) 2017 by Terasic Technologies Inc.
// ============================================================================
//
// Permission:
//
//   Terasic grants permission to use and modify this code for use
//   in synthesis for all Terasic Development Boards and Altera Development
//   Kits made by Terasic.  Other use of this code, including the selling
//   ,duplication, or modification of any portion is strictly prohibited.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Terasic provides no warranty regarding the use
//   or functionality of this code.
//
// ============================================================================
//
//  Terasic Technologies Inc
//  9F., No.176, Sec.2, Gongdao 5th Rd, East Dist, Hsinchu City, 30070. Taiwan
//
//
//                     web: http://www.terasic.com/
//                     email: support@terasic.com
//
// ============================================================================
//Date:  Wed Sep 20 14:19:17 2017
// ============================================================================

// ============================================================================
//
// Major Functions:     DE10-Nano Balance Car demo(NiosII version software) 
//                      Main routine entrance
//
// ============================================================================

// Revision History :
// ============================================================================
//   Ver  :| Author              :| Mod. Date   :| Changes Made:
//   V1.0 :| Sunshine            :| 2017/10/13  :| Initial Revision
// ============================================================================

#include <stdio.h>
#include <stdio.h>
#include "terasic_includes.h"
#include "Car.h"
#include "priv/alt_legacy_irq.h"
#include "system.h"
#include <math.h>
#include "MPU.h"
#include "kalman.h"
#include "IrRx.h"
#include "Command.h"

float  Angle_Balance,Gyro_Balance,Gyro_Turn,distance,vol,x_angle,PI=3.1415926;
int    demo_left,demo_right,Movement,cnt_ng,mode=0,flag=0,ng_count=0;
bool   stop_flag=false, demo=false,env=true,cmd_ut=false,pick_up=false,flag1=true;
alt_u8 led,led0,led1,led2,led3;
alt_32 balance_pwm,velocity_pwm,turn_pwm;
alt_u32 data32,temp32=0xdeadbeef;
MPU mpu(MPU_I2C_BASE, 0x68);
Kalman 	kalman;
CCar    Car(DC_MOTOR_LEFT_BASE, DC_MOTOR_RIGHT_BASE,MOTOR_MEASURE_LEFT_BASE,MOTOR_MEASURE_RIGHT_BASE);
CIrRx	IR(IR_RX_BASE, IR_RX_IRQ, IR_RX_IRQ_INTERRUPT_CONTROLLER_ID);
void Get_Angle();
void read_power(alt_u8 ch , alt_u16 *pRegValue);
bool CommandParsing(char *pCommand, int *pCommandID, int *pParam);
void uart_write(char *string);
void UnNomal_Check();
bool Restart_Check();
void MPU_INT_INIT();
void mpu_init_enable(bool enable);
void set_para();
int  balance(float Angle,float Gyro);
int  speed();
int  turn(float Gyro);
void MPU_INT_ISR(void * contex, alt_u32 id);

/**************************************************************************
Function     : Get Angle value (Kalman filter)
parameter    :
return value :
**************************************************************************/
void Get_Angle(void)
 {
 		int16_t ax, ay, az, gx, gy, gz;
 		mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 		Gyro_Balance=-gy;
 		x_angle=atan2(ax,az)*180/PI;
 		gy=gy/16.4;
 		Angle_Balance=kalman.getAngle(x_angle,-gy);
 		//printf("Angle_Balance=%f\r\n",Angle_Balance);
 		Gyro_Turn=gz;
 }

 /**************************************************************************
 Function     : ADC_LTC2308 Read power
 parameter    : Channel
 return value : Power data
 **************************************************************************/
void read_power(alt_u8 ch , alt_u16 *pRegValue){
 	int  Value;
 	// set measure number for ADC convert
 	IOWR(ADC_LTC2308_0_BASE, 0x01, 1);
 	// start measure
 	IOWR(ADC_LTC2308_0_BASE, 0x00, (ch << 1) | 0x00);
 	IOWR(ADC_LTC2308_0_BASE, 0x00, (ch << 1) | 0x01);
 	IOWR(ADC_LTC2308_0_BASE, 0x00, (ch << 1) | 0x00);
 	usleep(1);
 	while ((IORD(ADC_LTC2308_0_BASE,0x00) & 0x01) == 0x00);
 	Value = IORD(ADC_LTC2308_0_BASE, 0x01);
 	//printf("Value=%d\n",Value);
 	*pRegValue= Value;
 }

 /**************************************************************************
 Function     : Bluetooth Command Parsing
 parameter    : Command ��Command ID
 return value : Command Parsing data
 **************************************************************************/
bool CommandParsing(char *pCommand, int *pCommandID, int *pParam){
 	bool bFind = false;
 	int nNum, i, j , x=0;
 	bool find_equal = false;
 	char Data[10]={0};
 	nNum = sizeof(gCommandList)/sizeof(gCommandList[0]);

 	for(i=0;i<nNum && !bFind;i++){
 		if (strncmp(pCommand, gCommandList[i].szCommand, strlen(gCommandList[i].szCommand)) == 0){
 			*pCommandID = gCommandList[i].CommandId;
 			if (gCommandList[i].bParameter){
 				//*pParam = 10; //??
 				//for(j=0;pCommand[j]!=0x0a;j++){
 				for(j=0;pCommand[j]!=0x0d;j++){
 					if(find_equal==true){
 						Data[x] = pCommand[j];
 						x++;
 					}
 					else if(pCommand[j]=='=')
 						find_equal=true;
 				}
 				*pParam=atoi(Data);
 			}
 			bFind = true;
 		} // if
 	} // for
 	return bFind;
 }

 /**************************************************************************
 Function     : Bluetooth Data Send
 parameter    : data
 return value :
 **************************************************************************/
void uart_write(char *string)
 {
 	int i;
 	alt_32 temp;
 	int len=strlen(string);
 	for(i=0;i<len;i++)
 	{
 		temp=IORD(UART_BT_BASE,0x01);
 		temp=temp>>16&0xff;
 		if(temp>0)IOWR(UART_BT_BASE,0x0,*string++);
 		else i--;
 	}
 }

 /**************************************************************************
 Function     : UnNormal State Check
 parameter    : Angle_Balance value and power voltage
 return value :
 **************************************************************************/
 void  UnNomal_Check()
  {
  	if(pick_up||Angle_Balance>70||Angle_Balance<-70)
  	{
  		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x00);
  		Car.Pause();
  		Car.Stop_fast();
  		demo=false;
  		stop_flag=true;
  		pick_up=false;
  	}
  }

 /**************************************************************************
 Function     : Normal State Check and Restart Self-Balance
 parameter    :
 return value : 1:normal  0:UnNormal
 **************************************************************************/
 bool  Restart_Check()
  {
 	 if(x_angle<10&&x_angle>-10){
 		 return true;}
 	 else
 		 return false;
  }

 /**************************************************************************
 Function     : MPU6500 interrupt (MPU6500 INT pin trigger)
 parameter    :
 return value :
 **************************************************************************/
 void MPU_INT_INIT(void)
  {
  	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(MPU_INT_BASE,0x00);
  #ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
       if ((alt_ic_isr_register(MPU_INT_IRQ_INTERRUPT_CONTROLLER_ID,
                                     MPU_INT_IRQ,
                                        MPU_INT_ISR,
                                 NULL,
                                 NULL
                                 )!= 0))
  #else
      if((alt_irq_register(MPU_INT_IRQ,NULL, MPU_INT_ISR  )!= 0))
  #endif
      	{
  			  printf("register irt failed\r\n");
  		  }
  		IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x01);
  }

 /**************************************************************************
  Function     : MPU6500 Interrupt initialization
  parameter    :
  return value :
 **************************************************************************/
 void mpu_init_enable(bool enable)
  {
  	if(enable==TRUE)
  		IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x01);
  	else
  		IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x00);
  }

/**************************************************************************
Function     : Run the specified action (Demo Mode)
parameter    :
return value :
**************************************************************************/
void set_para(){
	static int count;
	static int count_times=0;
	//set Movement
 	if(Car.driver_direction&CAR_DIRECTION_FORWARD){
 		if((distance<25.0)&(mode==0x02)&(flag==0x02)) Movement=-10;
 		else if((distance<25.0)&(cmd_ut)&(flag==0x01)) Movement=-10;
 		else if(Angle_Balance<-10.0) Movement=-5;
 		else Movement=-48;}
 	else if(Car.driver_direction&CAR_DIRECTION_BACKWARD){
 		if(Angle_Balance>12.0) Movement=5;
 		else Movement=45;}
 	else
 		 Movement=0;
 	//Run the specified action (Demo Mode)
	if(demo)
	{
		Car.Pause();
		if(count_times==0)
		{
			Movement=-30;
			demo_left=40;
			demo_right=-40;
			count+=Gyro_Turn/1000;
			if(count>500){count_times=1;count=0;}
		}else if(count_times==1){
			Movement=-30;
			demo_left=-40;
			demo_right=40;
			count+=Gyro_Turn/1000;
			if(count<-500){
				count_times=2;
				count=0;
			};
		}else if(count_times==2){
			Movement=-40;
			demo_left=0;
			demo_right=0;
			count++;
			if(env){count_times=3;count=0;}
			else if(count==150){count_times=3;count=0;}
		}else if(count_times==3){
			Movement=0;
			demo_left=0;
			demo_right=0;
			if(abs(Car.Measure_L)+abs(Car.Measure_R)<10){count_times=4;count=0;}
		}
		else if(count_times==4)
		{
			Movement=-30;
			demo_left=40;
			demo_right=-40;
			count+=Gyro_Turn/1000;
			if(count>500){count_times=5;count=0;}
		}else if(count_times==5){
			Movement=-30;
			demo_left=-40;
			demo_right=40;
			count+=Gyro_Turn/1000;
			if(count<-500){count_times=6;count=0;};

		}else if(count_times==6){
			Movement=100;
			demo_left=0;
			demo_right=0;
			count++;
			if(env){count_times=7;count=0;}
			else if(count==150){count_times=7;count=0;}
		}else if(count_times==7){
			Movement=0;
			demo_left=0;
			demo_right=0;
			if(abs(Car.Measure_L)+abs(Car.Measure_R)<10){count_times=8;count=0;}
		}
		else if(count_times==8)
		{
			demo_left=100;
			demo_right=-100;
			count++;
			if(count==200){count_times=9;count=0;}
		}else if(count_times==9)
		{
			demo_left=-100;
			demo_right=100;
			count++;
			if(count==180){count_times=10;count=0;}
		}else if(count_times==10){
			Movement=0;
			demo_left=0;
			demo_right=0;
			if(abs(Car.Measure_L)+abs(Car.Measure_R)<10){count_times=11;count=0;}
		}
		else if(count_times==11){
			Movement=-100;
			demo_left=0;
			demo_right=0;
			count++;
			if(env){count_times=12;count=0;}
			else if(count==150){count_times=12;count=0;}
		}else{
			demo_left=0;
			demo_right=0;
			count_times=0;
			led3=0x00;
			demo=false;
		}

	}else {
		demo_left=0;
		demo_right=0;
		count=0;
		count_times=0;
	}
}

/**************************************************************************
Function     : Upright Closed-loop Control (PD)
parameter    : The Angle value��The angular velocity value
return value : Upright Closed-loop Control PWM
**************************************************************************/
int balance(float Angle,float Gyro)
 {
	 float Bias,kp=11.0,kd=0.02;
 	 int balance;
 	 Bias=Angle-1;
 	 balance=kp*Bias+Gyro*kd;
 	// printf("balance=%d\n",balance);
 	 return balance;
 }

/**************************************************************************
Function     : Speed Closed-loop Control (PI)
parameter    : The encoder values of the wheelthe
return value : Speed Closed-loop Control PWM
**************************************************************************/
int speed(void)
 {
     static float Speed,Encoder_Least,Encoder;
 	 static float Encoder_Integral;
 	 float kp=2.2,ki=0.05;
  	 Encoder_Least =(-Car.Measure_L+Car.Measure_R)-0;
  	 Encoder *= 0.8;
  	 Encoder += Encoder_Least*0.2;
  	 Encoder_Integral +=Encoder;
  	 Encoder_Integral=Encoder_Integral-Movement;
  	 if(Encoder_Integral>8000)  	Encoder_Integral=8000;
  	 if(Encoder_Integral<-8000)	Encoder_Integral=-8000;
  	 if(stop_flag)Encoder_Integral=0;
  	 Speed=Encoder*kp+Encoder_Integral*ki;
 	 return Speed;
 }

/**************************************************************************
Function     : Turn Closed-loop Control (PD)
parameter    : The Z axis gyroscope value
return value : Turn Closed-loop Control PWM
**************************************************************************/
int turn(float Gyro)
 {
	 float Bias,kp,kd;
 	 float turn_pwm;
 	 if(demo==true){
 		kp=1.0;kd=0.02;
 	 }else{
 		kp=0.3;kd=0.015;
 	 }
 	 Bias=Car.Measure_L+Car.Measure_R;
 	 if(Car.turn_direction&CAR_TURN_LEFT)
 	 	{
 			Bias+=110;
 		}else if(Car.turn_direction&CAR_TURN_RIGHT)
 		{
 			Bias-=110;
 		}
 	 if((led3==0)&&(Angle_Balance<10&&Angle_Balance>-10))
 		turn_pwm=0;
	 else
		turn_pwm=kp*Bias-kd*Gyro;
 	 return turn_pwm;
 }

/**************************************************************************
Function     : The interrupt function for 10ms
parameter    :
return value :
**************************************************************************/
#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT //nios2 91 edition or later
void MPU_INT_ISR(void *contex)
#else //before nios2 91 edition
void MPU_INT_ISR(void * contex, alt_u32 id)
#endif
{
	alt_32 static count=0;
  	int cnt;
  	const int nAdjust=15;
	if(!IORD_ALTERA_AVALON_PIO_EDGE_CAP(MPU_INT_BASE)){
		return;
	}else
	{
		IOWR_ALTERA_AVALON_PIO_EDGE_CAP(MPU_INT_BASE,0x00);
		IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x00);
		Get_Angle();
		Car.meaure_speed();
		cnt_ng=abs(Car.Measure_L)+abs(Car.Measure_R);
	  	if(vol<10.0)                 cnt=100-nAdjust;
	  	else if(vol>=10.0&&vol<10.5) cnt=110-nAdjust;
	  	else if(vol>=10.5&&vol<11.0) cnt=115-nAdjust;
	  	else if(vol>=11.0&&vol<11.5) cnt=120-nAdjust;
	  	else if(vol>=11.5&&vol<12.0) cnt=130-nAdjust;
	  	else if(vol>=12.0)           cnt=135-nAdjust;
		if(cnt_ng>=cnt)
			ng_count++;
		else
			ng_count=0;
		if(ng_count==30){
			pick_up=true;
			ng_count=0;
		}
		if(!stop_flag){
			led0=0x01;
			UnNomal_Check();
		}
		if(stop_flag)
		{
			if(Restart_Check())count++;
			else {
		  		led0=0x00;
		  		led2=0x00;
		  		led3=0x00;
				Car.Stop();
				count=0;
			}
			if(count==100)
			{
				led0=0x01;
				count=0;
				stop_flag=0;
				Car.Start();
			}
		}
			balance_pwm=balance(Angle_Balance,Gyro_Balance);
			set_para();
			turn_pwm=turn(Gyro_Turn);
			velocity_pwm=speed();
			Car.SetSpeed(-balance_pwm-velocity_pwm+turn_pwm+demo_left,-balance_pwm-velocity_pwm-turn_pwm+demo_right);//update PWM

	}
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x01);
}


/**************************************************************************
Function     : The main function
parameter    : data
return value :
**************************************************************************/
int main()
{
	alt_u32 data;
	alt_u32 temp;
  	alt_u8  number;
  	alt_u16 Data16;
  	char szADC_Data[10]={0};
  	int i=0;
  	int Command_EPS32,Command_IR,Param;
  	char szData[10];
  	printf("Hello BAL-Car\r\n");
  	mpu.initialize();
  	IR.Enable();
  	Car.Stop();
  	Car.Start();
  	Car.SetSpeed(0,0);
  	led1=0x00;
  	MPU_INT_INIT();
	while(1){
		//power calculation
		read_power(0x01 , &Data16);
        vol=(float)Data16*18.0/4.7/1000.0;
	    if(vol<10.5)
			led2=0x01;
	    else
		    led2=0x00;
	    //distance calculation
	    data = IORD(SONIC_DISTANCE_0_BASE,0x00);
	    distance = (float)data*34.0/100000.0;
	    mode = IORD(SW_BASE, 0x00) & 0x0f;
	    //Ultrosonic follow mode
	    if((mode&0x01)==0x01){
		led1=0x02;
			if((distance>10.0)&&(distance<20.0)){
				Car.Set_TurnFORWARD();
			}
			else if((distance>0.0)&&(distance<=10.0)){
				Car.Set_TurnBACKWARD();
			}
			else{
				Car.Pause();
			}
		}
	    //Normal mode (obstacle avoidance)
		else if((mode&0x01)==0x00){
			if(mode==0x02){ // IR control with Ultrosonic
				led1=0x01;
				if((flag==0x02)&(distance<=15)&Car.driver_direction&CAR_DIRECTION_FORWARD){
					led3=0x00;
					Car.Pause();
				}}
			else     led1=0x00;
			if(cmd_ut){     // Blue control with Ultrosonic
				if((flag==0x01)&(distance<=15)&Car.driver_direction&CAR_DIRECTION_FORWARD){
					led3=0x00;
					Car.Pause();
				}}
			// Bluetooth control
			temp=IORD(UART_BT_BASE,0x00);
			number=temp>>16;
			if(number!=0)
			{
				szData[i]=temp&0xff;
				i++;
				if((temp&0xff)==0x0a)
				{
					i=0;
					if(CommandParsing(szData, &Command_EPS32, &Param)){
						switch(Command_EPS32){
						case CMD_FOWARD:     //Forward
							if(cmd_ut){
								if(distance>15.0){
								led3=0x01;
								flag=0x01;
								demo=false;
								Car.Set_TurnFORWARD();
								}}
							else{
								led3=0x01;
								flag=0x00;
								demo=false;
								Car.Set_TurnFORWARD();
							}
							break;
						case CMD_BACKWARD:   //Backward
							led3=0x02;
							demo=false;
							Car.Set_TurnBACKWARD();
							break;
						case CMD_LEFT:      //Left
							led3=0x04;
							demo=false;
							Car.Set_TurnLEFT();
							break;
						case CMD_RIGHT:     //Right
							led3=0x08;
							demo=false;
							Car.Set_TurnRIGHT();
							break;
						case CMD_STOP:      //Stop
							led3=0x00;
							demo=false;
							Car.Pause();
							break;
						case CMD_AKBT:      //Send power value
							sprintf(szADC_Data,"%d\n",(alt_u32)(vol*1000));
							uart_write(szADC_Data);
							break;
						case CMD_ATUTON:    //Ultrosonic ON
							cmd_ut=true;
							break;
						case CMD_ATUTOFF:   //Ultrosonic OFF
							cmd_ut=false;
							break;
						case CMD_ATDM:      //Demo Mode switch
							if(demo){
								led3=0x00;
								demo=false;
							}
							else {
								led3=0x0f;
								demo=true;
							}
							 break;
						default:
							break;
						}
	   			}
	   		}}
			// IR Remote control
			if (!IR.IsEmpty()){
				Command_IR = IR.Pop();
				switch(Command_IR){
				case CIrRx::IR_NUM_5:     //Stop
					led3=0x00;
					demo=false;
					Car.Pause();
					break;
				case CIrRx::IR_NUM_2:     //Forward
					if(mode==0x02){
						if(distance>15.0){
						led3=0x01;
						flag=0x02;
						demo=false;
						Car.Set_TurnFORWARD();
						}}
					else{
						led3=0x01;
						flag=0x00;
						demo=false;
						Car.Set_TurnFORWARD();
					}
					break;
				case CIrRx::IR_NUM_8:     //Backward
					led3=0x02;
					demo=false;
					Car.Set_TurnBACKWARD();
					break;
				case CIrRx::IR_NUM_6:      //Right
					led3=0x8;
					demo=false;
					Car.Set_TurnRIGHT();
					break;
				case CIrRx::IR_NUM_4:      //Left
					led3=0x04;
					demo=false;
					Car.Set_TurnLEFT();
					break;
				case CIrRx::IR_NUM_A:      //Demo Mode switch
					if(demo){
						led3=0x00;
						demo=false;
					}
					else {
						led3=0x0f;
						demo=true;
					}
					break;
				default:
					break;
				}
				IR.Clear();
			}
		}
	led=((led0&0x01)<<7)|((led1&0x03)<<5)|((led2&0x01)<<4)|(led3&0x0f);
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,led);
     }
   return 0;
}//end main
