/*
 * Motor.c
 *
 *  Created on: 2015/11/6
 *      Author: User
 */

#include "Motor.h"
#include <stdio.h>
#include <math.h>




#define REG_TOTAL_DUR	0
#define REG_HIGH_DUR	1
#define REG_CTS			2

#define RUN_BIT			0x01
#define FORWARD_BIT		0x02
#define FAST_DECAY_BIT	0x04


#define CYCLE_WIDTH 		7000
#define CYCLE_WIDTH_MAX 	7000
#define CYCLE_WIDTH_MINI 	200

//#define CYCLE_WIDTH 		10000
//#define CYCLE_WIDTH_MAX 	9800
//#define CYCLE_WIDTH_MINI 	4900



#define     measure_cnt_enable_reg 0x01
#define     measure_cnt_write_reg  0x02
#define     measure_cnt_read_reg   0x00


/**************************************************************************
Function     :set motor PWM IP cyclone width of max/min
parameter    :
return value :
**************************************************************************/
CDcMotor::CDcMotor(int BaseAddress,int MeasureAddress):
	m_BaseAddress(BaseAddress),
	m_MeasureAddress(MeasureAddress),
	m_CycleWidthMini(CYCLE_WIDTH_MINI),
	m_CycleWidthMaxi(CYCLE_WIDTH_MAX)

{
	// TODO Auto-generated constructor stub

//	m_mmap = new CMMap(CMMap::MAP_H2F_LW_BRIDGE);

	IOWR(m_BaseAddress, REG_TOTAL_DUR, CYCLE_WIDTH);
}

CDcMotor::~CDcMotor() {
	// TODO Auto-generated destructor stub
	//delete m_mmap;
}


/**************************************************************************
Function     :set motor turn direction
parameter    :
return value :
**************************************************************************/
void CDcMotor::SetDirection(bool bFordward){
	int Status,Control;
	Status = IORD(m_BaseAddress, REG_CTS);
	if (bFordward)
		Control = Status | FORWARD_BIT;
	else
		Control = Status & ~FORWARD_BIT;
	IOWR(m_BaseAddress, REG_CTS, Control);
}


/**************************************************************************
Function     :set motor PWM value
parameter    :
return value :
**************************************************************************/

void CDcMotor::SetSpeed(float fSpeed /* -100~100*/){
	int SpeedParam = 0;

	// bound speed
	if (fSpeed < -100.0)
		fSpeed = -100;
	else if (fSpeed > 100.0)
		fSpeed = 100.0;
	//
	if (fSpeed != 0.0){
		SpeedParam = m_CycleWidthMini + (int)(fabs(fSpeed) * (float)(m_CycleWidthMaxi-m_CycleWidthMini) / 100.0);
		//SpeedParam = (int)(fabs(fSpeed) * (float)(m_CycleWidthMaxi) / 100.0);
	}

	IOWR(m_BaseAddress, REG_HIGH_DUR, SpeedParam);
	SetDirection((fSpeed >= 0.0)?true:false);
}

/**************************************************************************
Function     :stop motor normal
parameter    :
return value :
**************************************************************************/

void CDcMotor::Stop(void){
	int Status,Control;
	Status = IORD(m_BaseAddress, REG_CTS);
	Control = Status & (~RUN_BIT);
	IOWR(m_BaseAddress, REG_CTS, Control);
	IOWR(m_MeasureAddress, measure_cnt_enable_reg, 0x00);
}

/**************************************************************************
Function     :stop motor fastly
parameter    :
return value :
**************************************************************************/
void CDcMotor::Stop_fast(void){
	IOWR(m_BaseAddress, REG_CTS, 0x00);
	IOWR(m_MeasureAddress, measure_cnt_enable_reg, 0x00);
}

/**************************************************************************
Function     :start motor
parameter    :
return value :
**************************************************************************/
void CDcMotor::Start(void){
	int Status,Control;
	Status = IORD(m_BaseAddress, REG_CTS);
	Control = Status | RUN_BIT;
	IOWR(m_BaseAddress, REG_CTS, Control);
	IOWR(m_MeasureAddress, measure_cnt_enable_reg, 0x01);
}

/**************************************************************************
Function     :fetch the motor speed count
parameter    :
return value :
**************************************************************************/

signed short CDcMotor::GetCount(void){
	 signed short count;
	 count=IORD(m_MeasureAddress, measure_cnt_read_reg);
	 IOWR(m_MeasureAddress, measure_cnt_write_reg, 0x8000);
	 count=count-0x8000;
	 return count;
}



