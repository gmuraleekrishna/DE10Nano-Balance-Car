/*
 * Car.cpp
 *
 *  Created on: 2016/3/15
 *      Author: User
 */

#include "Car.h"
#include <stdio.h>

#define BOUND(x, mini_value, maxi_value)  (   ((x) < mini_value)?(mini_value):(((x) > maxi_value)?maxi_value:(x))   )
/**************************************************************************
Function     : fetch car speed
parameter    :
return value :
**************************************************************************/
CCar::CCar(int MotorL_BaseAddress, int MotorR_BaseAddress,int MeasureL_BaseAddress,int MeasureR_BaseAddress):
	m_MotorL(MotorL_BaseAddress,MeasureL_BaseAddress),
	m_MotorR(MotorR_BaseAddress,MeasureR_BaseAddress),
	m_bIsStarted(false)
	{

	// TODO Auto-generated constructor stub
	Stop();

}

CCar::~CCar() {
	// TODO Auto-generated destructor stub
	Stop();
}

/**************************************************************************
Function     : start car
parameter    :
return value :
**************************************************************************/

void CCar::Start(void) {
	// TODO Auto-generated destructor stub
	m_MotorL.Start();
	m_MotorR.Start();
	m_bIsStarted = true;
}

/**************************************************************************
Function     : normal stop car
parameter    :
return value :
**************************************************************************/
void CCar::Stop() {
	// TODO Auto-generated destructor stub
	m_MotorL.Stop();
	m_MotorR.Stop();
	m_bIsStarted = false;
}

/**************************************************************************
Function     : stop car fastly
parameter    :
return value :
**************************************************************************/

void CCar::Stop_fast() {
	// TODO Auto-generated destructor stub
	m_MotorL.Stop_fast();
	m_MotorR.Stop_fast();
	m_bIsStarted = false;
}

/**************************************************************************
Function     :pause fastly
parameter    :
return value :
**************************************************************************/

void CCar::Pause() {
	// TODO Auto-generated destructor stub
	//SetSpeed(0);
	Set_DriveDirection(0x00);
	Set_TurnDirection(0x00);
}

/**************************************************************************
Function     :set car speed of both
parameter    :
return value :
**************************************************************************/

void CCar::SetSpeed(float SpeedL, float SpeedR){

	m_MotorL.SetSpeed(SpeedL);
	m_MotorR.SetSpeed(SpeedR);

}
/**************************************************************************
Function     :set car speed of single
parameter    :
return value :
**************************************************************************/

void CCar::SetSpeed(float Speed){
	SetSpeed(Speed, Speed);

}

/**************************************************************************
Function     :return the car status of start
parameter    :
return value :
**************************************************************************/

bool CCar::IsStarted(void){
	return m_bIsStarted;
}


/**************************************************************************
Function     :measure the car speed
parameter    :
return value :
**************************************************************************/

void CCar::meaure_speed(void)
{
	Measure_L=m_MotorL.GetCount();
	Measure_R=m_MotorR.GetCount();
}

/**************************************************************************
Function     :set the car direction
parameter    :
return value :
**************************************************************************/
void CCar::Set_DriveDirection(unsigned char m_direction)
{
	driver_direction=m_direction;
	Set_TurnDirection(0x00);
}

/**************************************************************************
Function     :set the car turn direction
parameter    :
return value :
**************************************************************************/
void CCar::Set_TurnDirection(unsigned char m_direction)
{
	turn_direction=m_direction;
}


/**************************************************************************
Function     :set the car turn FORWARD
parameter    :
return value :
**************************************************************************/
void CCar::Set_TurnFORWARD()
{
	Set_DriveDirection(CAR_DIRECTION_FORWARD);
	Set_TurnDirection(0x00);
}

/**************************************************************************
Function     :set the car turn BACKWARD
parameter    :
return value :
**************************************************************************/
void CCar::Set_TurnBACKWARD()
{
	Set_DriveDirection(CAR_DIRECTION_BACKWARD);
	Set_TurnDirection(0x00);
}

/**************************************************************************
Function     :set the car turn LEFT
parameter    :
return value :
**************************************************************************/
void CCar::Set_TurnLEFT()
{
	Set_TurnDirection(CAR_TURN_LEFT);
}

/**************************************************************************
Function     :set the car turn RIGHT
parameter    :
return value :
**************************************************************************/
void CCar::Set_TurnRIGHT()
{
	Set_TurnDirection(CAR_TURN_RIGHT);
}
