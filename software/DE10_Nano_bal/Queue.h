/*
 * Queue.h
 *
 *  Created on: 2016/3/23
 *      Author: User
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "terasic_includes.h"

class CQueue {
protected:
	alt_u32 m_nNum;
	alt_u32 m_nFront;
	alt_u32 m_nRear;
	alt_u32 *m_szQueue;

public:
	CQueue(const int nQueueSize = 8);
	virtual ~CQueue();

	bool IsEmpty(void);
	bool IsFull(void);
	bool Push(alt_u32 data32);
	alt_u32 Pop(void);
	void Clear(void); // clear queue
};

#endif /* QUEUE_H_ */
