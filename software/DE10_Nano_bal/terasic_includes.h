// --------------------------------------------------------------------
// Copyright (c) 2013 by Terasic Technologies Inc.
// --------------------------------------------------------------------
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
// --------------------------------------------------------------------
//           
//                     Terasic Technologies Inc
//                     356 Fu-Shin E. Rd Sec. 1. JhuBei City,
//                     HsinChu County, Taiwan
//                     302
//
//                     web: http://www.terasic.com/
//                     email: support@terasic.com
//
// --------------------------------------------------------------------

// ============================================================================
//
// Major Functions:     DE10-Nano Balance Car demo(NiosII version)
//
// ============================================================================

// Revision History :
// ============================================================================
//   Ver  :| Author              :| Mod. Date   :| Changes Made:
//   V1.0 :| Sunshine            :| 2017/10/13  :| Initial Revision
// ============================================================================


#ifndef TERASIC_INCLUDES_H_
#define TERASIC_INCLUDES_H_

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>
#include <stddef.h>
#include <unistd.h>  // usleep (unix standard?)
#include "sys/alt_flash.h"
#include "sys/alt_flash_types.h"
#include "io.h"
#include "alt_types.h"  // alt_u32
#include "altera_avalon_pio_regs.h" //IOWR_ALTERA_AVALON_PIO_DATA
#include "sys/alt_irq.h"  // interrupt
#include "sys/alt_alarm.h" // time tick function (alt_nticks(), alt_ticks_per_second())
#include "sys/alt_timestamp.h" 
#include "sys/alt_stdio.h"
#include "system.h"
#include <fcntl.h>
//#include "debug.h"

#define DEBUG_DUMP  /*printf */ 
/*
#ifndef __cplusplus
typedef int bool;
#define TRUE    1
#define FALSE   0
#endif
*/
#define TRUE    1
#define FALSE   0
typedef alt_u8 	uint8_t;
typedef alt_u16 uint16_t;
typedef alt_u32 uint32_t;
typedef alt_8 	int8_t;
typedef alt_16 	int16_t;
typedef alt_32 	int32_t;


#endif /*TERASIC_INCLUDES_H_*/
