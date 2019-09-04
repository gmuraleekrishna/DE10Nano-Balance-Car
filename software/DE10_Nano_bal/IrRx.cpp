/*
 * IrRx.cpp
 *
 *  Created on: 2016/3/23
 *      Author: User
 */

#include "IrRx.h"
#include "terasic_includes.h"
#include "sys/alt_irq.h"  // interrupt
void ir_isr(void* context, alt_u32 id){
	CIrRx *pIrRx = (CIrRx *)context;
    alt_u32 ScanCode;
    IOWR(pIrRx->m_IRM_BASE, 0, 0);
   // IOWR(LED_BASE, 0x00, 0xAA);
    //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x00);
    if (pIrRx){
    	ScanCode = IORD(pIrRx->m_IRM_BASE, 0);

    	if (!pIrRx->IsFull()){
    		pIrRx->Push(ScanCode);
    	}
    	pIrRx->ClearInterrupt();
    }

    // clear irq
    //IOWR(pIrRx->m_IRM_BASE, 0, 0);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(pIrRx->m_IRM_BASE,0);


}


CIrRx::CIrRx(const alt_u32 IRM_BASE, const alt_u32 IRM_IRQ, const alt_u32 IRM_IRQ_INTERRUPT_CONTROLLER_ID):
CQueue(8),
m_IRM_BASE(IRM_BASE),
m_IRM_IRQ(IRM_IRQ),
m_IRM_IRQ_INTERRUPT_CONTROLLER_ID(IRM_IRQ_INTERRUPT_CONTROLLER_ID)
{
	// TODO Auto-generated constructor stub

}

CIrRx::~CIrRx() {
	// TODO Auto-generated destructor stub
}


bool CIrRx::Enable(void){
	bool bSuccess = false;
	int error;

	CQueue::Clear();
	// enable interrupt
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(m_IRM_BASE,0x01);
	// clear capture flag
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(m_IRM_BASE,0);
        //
	error = alt_irq_register(m_IRM_IRQ,this,ir_isr);

	bSuccess = error?false:true;

	return bSuccess;
}


void CIrRx::Disable(void){
   	alt_irq_disable(m_IRM_IRQ_INTERRUPT_CONTROLLER_ID);
   	CQueue::Clear();
}

void CIrRx::Test(void){
	int nIndex = 1;
	if (!Enable()){
		printf("failed to enable IR\r\n");
	}else{
		printf("Enable ir\r\n");
		while(1){
			if (!IsEmpty()){
				printf("[%d]%04xh\r\n", nIndex++, Pop());
			}
		}
	}

}

void CIrRx::ClearInterrupt(void){
	IOWR(m_IRM_BASE, 0, 0); // write any value to clear interrupt
	//IOWR_ALTERA_AVALON_PIO_IRQ_MASK(MPU_INT_BASE,0x00);
}
