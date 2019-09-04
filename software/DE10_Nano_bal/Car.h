/*
 * CCar.h
 *
 *  Created on: 2016/3/15
 *      Author: User
 */

#ifndef CCAR_H_
#define CCAR_H_

#include "motor.h"

#define CAR_DIRECTION_FORWARD   0x01
#define CAR_DIRECTION_BACKWARD  0x02
#define CAR_TURN_LEFT   	0x01
#define CAR_TURN_RIGHT  	0x02

class CCar {
protected:
	CDcMotor m_MotorL;
	CDcMotor m_MotorR;
	bool m_bIsStarted;

public:
	signed short  Measure_L, Measure_R;
	unsigned char driver_direction;
	unsigned char turn_direction;
	CCar(int MotorL_BaseAddress, int MotorR_BaseAddress,int MeasureL_BaseAddress,int MeasureR_BaseAddress);
	~CCar();

	void Start(void);
	void Stop();
	void Stop_fast();
	void Pause();
	void Resume();
	bool IsStarted();
	void SetSpeed(float SpeedL, float SpeedR);
	void SetSpeed(float Speed);
	void meaure_speed();
	void Set_DriveDirection(unsigned char m_direction);
	void Set_TurnDirection(unsigned char m_direction);
	void Set_TurnFORWARD();
	void Set_TurnBACKWARD();
	void Set_TurnLEFT();
	void Set_TurnRIGHT();

};

#endif /* CCAR_H_ */
