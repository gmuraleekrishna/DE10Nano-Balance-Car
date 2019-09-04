/*
 * Motor.h
 *
 *  Created on: 2015/11/6
 *      Author: User
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "terasic_includes.h"

class CDcMotor  {
protected:
	int m_BaseAddress;
	int m_MeasureAddress;
	int m_CycleWidthMini;
	int m_CycleWidthMaxi;
	void SetDirection(bool bFordward);


public:
	CDcMotor(int BaseAddress,int MeasureAddress);
	virtual ~CDcMotor();

	void SetSpeed(float fSpeed /* -100~100*/);
	void Stop(void);
	void Stop_fast(void);
	void Start(void);
	signed short GetCount(void);
};


#endif /* MOTOR_H_ */
