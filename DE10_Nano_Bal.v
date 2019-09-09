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
//
// Major Functions:     DE10-Nano Balance Car demo(NiosII version)
//
// ============================================================================
//
// Revision History :
// ============================================================================
//   Ver  :| Author              :| Mod. Date   :| Changes Made:
//   V1.2 :| Sunshine            :| 2018/7/10   :| Revision D
// ============================================================================

//=======================================================
//  Macros definition
//=======================================================

//user interface macro definition, if use the interface, uncomment the corresponding line , otherwise comment it.
 `default_nettype none   //avoid implict declaration
 
//`define ENABLE_HPS     //HPS    interface     


//=======================================================
//  Moudle and entity definition
//=======================================================

module DE10_Nano_Bal(

      ///////// FPGA /////////
      FPGA_CLK1_50,      //FPGA clock 50MHz bank3b
      FPGA_CLK2_50,      //FPGA clock 50MHz bank4a
      FPGA_CLK3_50,      //FPGA clock 50MHz bank8a
		
		///////// ADC LTC2308/////////////
      ADC_CONVST,        //ADC  Convst Start 
      ADC_SCK,           //ADC chip data interface  Serial clock 
      ADC_SDI,           //ADC chip data interface  Serial data in 
      ADC_SDO,           //ADC chip data interface  Serial data out 

      ///////// ARDUINO /////////
      ARDUINO_IO,        //ARDUINO_IO [15:0]
      ARDUINO_RESET_N,   //ARDUINO reset

      
      ///////// GPIO /////////
      //GPIO_0,            //connection for BAL daughter card GPIO_0[31:0]
      GPIO_1,            //GPIO 1 unconectted GPIO_1[31:0]

      ///////// HDMI Tx 1080p/////////
      HDMI_I2C_SCL,      //HDMI I2C Serial clock   
      HDMI_I2C_SDA,      //HDMI I2C Serial data 
		
      HDMI_I2S,          //HDMI I2S for audio
      HDMI_LRCLK,        //HDMI LR channel clock for audio
      HDMI_MCLK,         //HDMI main clock for audio
      HDMI_SCLK,         //HDMI serial clock for audio
		
      HDMI_TX_CLK,       //HDMI tx pixel clock for video
      HDMI_TX_D,         //HDMI tx pixel data for video
      HDMI_TX_DE,        //HDMI tx pixel data field enable/valid for video
      HDMI_TX_HS,        //HDMI tx pixel data field horizontal sync for video
      HDMI_TX_VS,        //HDMI tx pixel data field veritical sync for video
		HDMI_TX_INT,       //HDMI tx INT    

`ifdef ENABLE_HPS
      ///////// HPS interface/////////
      
		//HPS DDR3, 2-chip, 1GB x32 
      HPS_DDR3_ADDR,     //HPS ddr3 chip address bus  HPS_DDR3_ADDR[14:0]
      HPS_DDR3_BA,       //HPS ddr3 chip bank address HPS_DDR3_BA[2:0]
      HPS_DDR3_CAS_N,    //HPS ddr3 chip column addres select(active low)
      HPS_DDR3_CKE,      //HPS ddr3 chip column addres select(active low)
      HPS_DDR3_CK_N,     //HPS ddr3 chip negative clock
      HPS_DDR3_CK_P,     //HPS ddr3 chip positive clock
      HPS_DDR3_CS_N,     //HPS ddr3 chip select(active low)
      HPS_DDR3_DM,       //HPS DDR3 chip datamask bus  HPS_DDR3_DM[3:0]
      HPS_DDR3_ODT,      //HPS DDR3 chip on-die termination
      HPS_DDR3_RAS_N,    //HPS ddr3 chip row addres select(active low)
      HPS_DDR3_RESET_N,  //HPS ddr3 chip reset#
      HPS_DDR3_WE_N,     //HPS ddr3 chip write enable(active low)
		HPS_DDR3_DQ,       //HPS ddr3 chip data bus, HPS_DDR3_DQ[31:0] 
      HPS_DDR3_DQS_N,    //HPS ddr3 chip data syn negative, HPS_DDR3_DQS_N[3:0]
      HPS_DDR3_DQS_P,    //HPS ddr3 chip data syn positive, HPS_DDR3_DQS_P[3:0]
		HPS_DDR3_RZQ,      //HPS ddr3 chip Calibration resistor input
		
		//HPS ethernet RGMII interface
      HPS_ENET_GTX_CLK,  //HPS ethernet tx clock
      HPS_ENET_TX_DATA,  //HPS ethernet tx data, HPS_ENET_TX_DATA[3:0]
		HPS_ENET_TX_EN,    //HPS ethernet tx control, HPS_ENET_TX_DATA[3:0]
		HPS_ENET_MDC,      //HPS ethernet MDIO interface serial clock
		HPS_ENET_MDIO,     //HPS ethernet MDIO interface serial data
      HPS_ENET_RX_CLK,   //HPS ethernet rx clock
      HPS_ENET_RX_DATA,  //HPS ethernet rx clock, HPS_ENET_RX_DATA[3:0]
      HPS_ENET_RX_DV,    //HPS ethernet rx control,
		HPS_ENET_INT_N,    //HPS ethernet rx control,
		
		//HPS g-sensor
      HPS_GSENSOR_INT,   //HPS g-sensor INT#
		
		//I2C
      HPS_I2C0_SCLK,     //HPS I2C0 serial clock
      HPS_I2C0_SDAT,     //HPS I2C0 serial clock
      HPS_I2C1_SCLK,     //HPS I2C1 serial clock
      HPS_I2C1_SDAT,     //HPS I2C1 serial clock
		
      HPS_KEY,           //HPS KEY
      HPS_LED,           //HPS LED
		
      HPS_LTC_GPIO,      //HPS LTC GPIO
		//sd card
      HPS_SD_CLK,        //SD card clock
      HPS_SD_CMD,        //SD card command
      HPS_SD_DATA,       //SD card data bus HPS_SD_DATA[3:0]
		
		//spi interface
      HPS_SPIM_CLK,      //SPI clock
      HPS_SPIM_MISO,     //SPI master input slave output
      HPS_SPIM_MOSI,     //SPI master output slave input
      HPS_SPIM_SS,       //SPI SS
		
		//uart
      HPS_UART_RX,       //HPS uart rx    
      HPS_UART_TX,       //HPS uart tx    
		HPS_CONV_USB_N,   // HPS uart power control
		
		//usb ULPI interface
      HPS_USB_CLKOUT,    //HPS usb ULPI sync clock
      HPS_USB_DATA,      //HPS usb data bus HPS_USB_DATA[7:0]
      HPS_USB_DIR,       //HPS usb ULPI DIR
      HPS_USB_NXT,       //HPS usb ULPI NXT
      HPS_USB_STP,       //HPS usb ULPI STP
		
`endif /*ENABLE_HPS*/

      ///////// KEY /////////
      KEY,               //default high input KEY[1:0] 

      ///////// LED /////////
      LED,               //green LED  LED[7:0]

      ///////// SW /////////
      SW,                //DIP SW[3:0]
		
		//////////// GPIO_0, GPIO_0 connect to BAL Daughtercard //////////	

      //Infrared module
		IR_RXD,	          //ir receiver 
		//right Motor speed measure and control 
		MTR_PWMA,          //motor pwm A
		MTRR_P,	          //motor direction control input 1
		MTRR_N,	          //motor direction control input 2
		MTRR_A,            //motor spped measure input A 
		MTRR_B,	          //motor spped measure input B
		
		//left Motor speed measure and control 
		MTR_PWMB,          //motor pwm 
		MTRL_P,	          //motor direction control input 1 
		MTRL_N,	          //motor direction control input 2
		MTRL_A,            //motor spped measure input A 
		MTRL_B,	          //motor spped measure input B
	   //left and right motor standby	
		MTR_STBY,          //motor standby 
		
		//MPU6500 6-axis sensor, I2C interface
		MPU_CS_n,          //MPU6500 chip select(active low)	
		MPU_SCL_SCLK,      //MPU6500 I2C serial clock
		MPU_AD0_SDO,       //MPU6500 I2C address A0
		MPU_SDA_SDI,       //MPU6500 I2C serial data
		MPU_INT, 	       //MPU6500 INT#
		
		//ultra sonic
		SONIC_TRIGGER,     //ultra sonic trigger output
		SONIC_ECHO,        //ultra sonic echo input
		
		//ESP32 wifi and bluetooth module uart interface with FPGA
	   ESP32_EN,          //ESP32 enable (active high)
      ESP32_UART0_TX,    //ESP32 UART0 Tx 
		ESP32_UART0_RTS,	 //ESP32 UART0 RTS 			
		ESP32_UART0_RX,    //ESP32 UART0 Rx 		
		ESP32_UART0_CTS,   //ESP32 UART0 CTS 		
		ESP32_CMD	       //ESP32 reserved
		
		
);

///////// ADC /////////
      output             ADC_CONVST;
      output             ADC_SCK;
      output             ADC_SDI;
      input              ADC_SDO;

      ///////// ARDUINO /////////
      inout       [15:0] ARDUINO_IO;
      inout              ARDUINO_RESET_N;

      ///////// FPGA /////////
      input              FPGA_CLK1_50;
      input              FPGA_CLK2_50;
      input              FPGA_CLK3_50;

      ///////// GPIO /////////
      //inout       [35:0] GPIO_0; //connectd with BAL daughter card
      inout       [35:0] GPIO_1;

      ///////// HDMI /////////
      inout              HDMI_I2C_SCL;
      inout              HDMI_I2C_SDA;
      inout              HDMI_I2S;
      inout              HDMI_LRCLK;
      inout              HDMI_MCLK;
      inout              HDMI_SCLK;
      output             HDMI_TX_CLK;
      output      [23:0] HDMI_TX_D;
      output             HDMI_TX_DE;
      output             HDMI_TX_HS;
      output             HDMI_TX_VS;
		input              HDMI_TX_INT;

`ifdef ENABLE_HPS
      ///////// HPS /////////
      //DDR3
      output      [14:0] HPS_DDR3_ADDR;
      output      [2:0]  HPS_DDR3_BA;
      output             HPS_DDR3_CAS_N;
      output             HPS_DDR3_CKE;
      output             HPS_DDR3_CK_N;
      output             HPS_DDR3_CK_P;
      output             HPS_DDR3_CS_N;
      output      [3:0]  HPS_DDR3_DM;
		output             HPS_DDR3_ODT;
      output             HPS_DDR3_RAS_N;
      output             HPS_DDR3_RESET_N;
		output             HPS_DDR3_WE_N;
      inout       [31:0] HPS_DDR3_DQ;
      inout       [3:0]  HPS_DDR3_DQS_N;
      inout       [3:0]  HPS_DDR3_DQS_P;
      input              HPS_DDR3_RZQ;
      //Ethernet RGMII interface
      output             HPS_ENET_GTX_CLK; 
      output             HPS_ENET_MDC;
      output      [3:0]  HPS_ENET_TX_DATA;
      output             HPS_ENET_TX_EN;
		inout              HPS_ENET_MDIO;
      input              HPS_ENET_RX_CLK;
      input       [3:0]  HPS_ENET_RX_DATA;
      input              HPS_ENET_RX_DV;
		input              HPS_ENET_INT_N;
		//HPS g-sensor
      inout              HPS_GSENSOR_INT;
		//I2C
      inout              HPS_I2C0_SCLK;
      inout              HPS_I2C0_SDAT;
      inout              HPS_I2C1_SCLK;
      inout              HPS_I2C1_SDAT;
		
      inout              HPS_KEY;
      inout              HPS_LED;
		//LTC GPIO
      inout              HPS_LTC_GPIO;
		//SD card
      output             HPS_SD_CLK;
      inout              HPS_SD_CMD;
      inout       [3:0]  HPS_SD_DATA;
		//SPI interface
      output             HPS_SPIM_CLK;
      input              HPS_SPIM_MISO;
      output             HPS_SPIM_MOSI;
      inout              HPS_SPIM_SS;
		//UART
      input              HPS_UART_RX;
      output             HPS_UART_TX;
		inout              HPS_CONV_USB_N;
		//USB 
      input              HPS_USB_CLKOUT;
      inout       [7:0]  HPS_USB_DATA;
      input              HPS_USB_DIR;
      input              HPS_USB_NXT;
      output             HPS_USB_STP;
`endif /*ENABLE_HPS*/

      ///////// KEY /////////
      input       [1:0]  KEY;

      ///////// LED /////////
      output      [7:0]  LED;

      ///////// SW /////////
      input       [3:0]  SW;
		
		//////////// GPIO_0; GPIO_0 connect to Smart Car Daughtercard //////////	
      //Irda
		input 		       IR_RXD;		
	
	   //motor standby
		output	          MTR_STBY;
		//right Motor speed measure and control 
		output				 MTR_PWMA;
		output		       MTRR_N;		
		output		       MTRR_P;
	   input					 MTRR_A;
		input					 MTRR_B;
	   //left Motor speed measure and control 
		output				 MTR_PWMB;
		output	          MTRL_P;		
		output	          MTRL_N;	
		input					 MTRL_A;
		input					 MTRL_B;	
		//MPU6500
		output 				 MPU_CS_n;		
		output             MPU_SCL_SCLK;
		output				 MPU_AD0_SDO;
		inout					 MPU_SDA_SDI;
		input					 MPU_INT;	
		//ultra sonic
		output  				 SONIC_TRIGGER;
		input  				 SONIC_ECHO;	
		//ESP32
		output				 ESP32_EN;
      output	          ESP32_UART0_TX;
      output	          ESP32_UART0_RTS;	
	   input  				 ESP32_UART0_RX;		
		input  			    ESP32_UART0_CTS;	
		input  	  [8:0]   ESP32_CMD;		

//=======================================================
//  REG/WIRE declarations
//=======================================================
//ESP32 
wire    cts,rts;
wire    rxd,txd;
wire    MTRL_A_fir;
wire    MTRL_B_fir;
wire    MTRR_A_fir;
wire    MTRR_B_fir;		
//=======================================================
//  Structural coding
//=======================================================

//Motor control
assign  MTR_STBY = 1'b0;  //no standby

//ESP32 
assign  ESP32_EN        = 1'b1; //enable esp32
assign  ESP32_UART0_TX  = txd;
assign  rxd 				= ESP32_UART0_RX;

//MPU6500
assign  MPU_AD0_SDO  = 1'b0; //I2C addr
assign  MPU_CS_n     = 1'b1; //enable I2C

FILTER fir_mtrl(   
                .iCLK(FPGA_CLK2_50),
                .iRST_N(1'b1),                                               
                .iDATA_A(MTRL_A),
					 .iDATA_B(MTRL_B),
				    .ODATA_A(MTRL_A_fir),
					 .ODATA_B(MTRL_B_fir)
               );
														
FILTER fir_mtrr(   
                .iCLK(FPGA_CLK2_50),
                .iRST_N(1'b1),                                               
                .iDATA_A(MTRR_A),
					 .iDATA_B(MTRR_B),
				    .ODATA_A(MTRR_A_fir),
					 .ODATA_B(MTRR_B_fir)
               );					
					
Qsys u0 (
			//clock && reset
        .clk_clk                                          (FPGA_CLK2_50),                  	// clk.clk
        .reset_reset_n                                    (1'b1),                          	// reset.reset_n
			
			//right motor control  	  
        .dc_motor_right_conduit_end_pwm                 (MTR_PWMA),                 	 		// dc_motor_right_conduit_end_1.pwm
        .dc_motor_right_conduit_end_motor_in1           (MTRR_P),                     		//                       .motor_in1
        .dc_motor_right_conduit_end_motor_in2           (MTRR_N),           					//                       .motor_in2

		  //left motor control
        .dc_motor_left_conduit_end_pwm                  (MTR_PWMB),                  		// dc_motor_left_conduit_end_1.pwm
        .dc_motor_left_conduit_end_motor_in1            (MTRL_N),            					//                        .motor_in1
        .dc_motor_left_conduit_end_motor_in2            (MTRL_P),    	        					//                        .motor_in2
		  
		  //left motor speed measure	  	  
		  .motor_measure_left_conduit_end_ab                ({MTRL_A_fir,MTRL_B_fir}),         // motor_measure_left_conduit_end.ab
        //right motor speed measure	  	 
		  .motor_measure_right_conduit_end_ab               ({MTRR_A_fir,MTRR_B_fir}),         // motor_measure_right_conduit_end.ab

		  //mpu6500 		  
		  .mpu_i2c_export_scl_pad_io                        (MPU_SCL_SCLK ),            			// mpu_i2c_export.scl_pad_io
        .mpu_i2c_export_sda_pad_io                        (MPU_SDA_SDI ),            			//               .sda_pad_io
        .mpu_int_external_connection_export               (MPU_INT ),                			// mpu_int_external_connection.export

		  //uart 		  
        .uart_bt_external_interface_RXD                   (rxd),                   				// uart_bt_external_interface.RXD
        .uart_bt_external_interface_TXD                   (txd),                    			//                           .TXD

		  //pio 		  
        //.led_external_connection_export                   (LED),                    			// led_external_connection.export
		  .direction_controller_0_conduit_end_led_readdata		(LED),
		  .sw_external_connection_export                    (SW),                     			// sw_external_connection.export
 
 		  //sonic 
		  .sonic_distance_0_conduit_end_echo                (SONIC_ECHO),                		// sonic_distance_0_conduit_end.echo
		  .sonic_distance_0_conduit_end_trigger             (SONIC_TRIGGER),              		//                             .trigger
 
 		  //esp32 pio        
		  .esp32_io_external_connection_export              (ESP32_CMD[2:0]),              		// esp32_io_external_connection.export
 
  		  //ltc2308 adc 
        .adc_ltc2308_0_conduit_end_CONVST                 (ADC_CONVST),                 		// adc_ltc2308_0_conduit_end.CONVST
        .adc_ltc2308_0_conduit_end_SCK                    (ADC_SCK),                    		//                          .SCK
        .adc_ltc2308_0_conduit_end_SDI                    (ADC_SDI),                    		//                          .SDI
        .adc_ltc2308_0_conduit_end_SDO                    (ADC_SDO),                     	   //                          .SDO
		  
  		  //ir		  
        .ir_rx_conduit_end_export                         (IR_RXD),                           // ir_rx_conduit_end.export
		  
		  // custom
		  // leds array interface
		  .direction_controller_0_conduit_leds_array_export (GPIO_1[7:0])
	 );
	 	
endmodule //end DE10_Nano_Bal module
