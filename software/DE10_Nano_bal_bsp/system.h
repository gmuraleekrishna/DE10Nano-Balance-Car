/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'Qsys'
 * SOPC Builder design path: ../../Qsys.sopcinfo
 *
 * Generated: Thu Jan 25 17:15:20 GMT+08:00 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x01100820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x19
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x01080020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x19
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x01080000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x01100820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x19
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x01080020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x19
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x01080000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ADC_LTC2308
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_UP_AVALON_RS232
#define __I2C_OPENCORES
#define __MOTOR_MEASURE
#define __SONIC_DISTANCE
#define __TERASIC_DC_MOTOR_PWM
#define __TERASIC_IRM


/*
 * LED configuration
 *
 */

#define ALT_MODULE_CLASS_LED altera_avalon_pio
#define LED_BASE 0x20
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 8
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/LED"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x11010c0
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x11010c0
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x11010c0
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Qsys"


/*
 * adc_ltc2308_0 configuration
 *
 */

#define ADC_LTC2308_0_BASE 0x30
#define ADC_LTC2308_0_IRQ -1
#define ADC_LTC2308_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ADC_LTC2308_0_NAME "/dev/adc_ltc2308_0"
#define ADC_LTC2308_0_SPAN 8
#define ADC_LTC2308_0_TYPE "adc_ltc2308"
#define ALT_MODULE_CLASS_adc_ltc2308_0 adc_ltc2308


/*
 * dc_motor_left configuration
 *
 */

#define ALT_MODULE_CLASS_dc_motor_left TERASIC_DC_MOTOR_PWM
#define DC_MOTOR_LEFT_BASE 0x11010a0
#define DC_MOTOR_LEFT_IRQ -1
#define DC_MOTOR_LEFT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DC_MOTOR_LEFT_NAME "/dev/dc_motor_left"
#define DC_MOTOR_LEFT_SPAN 16
#define DC_MOTOR_LEFT_TYPE "TERASIC_DC_MOTOR_PWM"


/*
 * dc_motor_right configuration
 *
 */

#define ALT_MODULE_CLASS_dc_motor_right TERASIC_DC_MOTOR_PWM
#define DC_MOTOR_RIGHT_BASE 0x1101090
#define DC_MOTOR_RIGHT_IRQ -1
#define DC_MOTOR_RIGHT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DC_MOTOR_RIGHT_NAME "/dev/dc_motor_right"
#define DC_MOTOR_RIGHT_SPAN 16
#define DC_MOTOR_RIGHT_TYPE "TERASIC_DC_MOTOR_PWM"


/*
 * esp32_io configuration
 *
 */

#define ALT_MODULE_CLASS_esp32_io altera_avalon_pio
#define ESP32_IO_BASE 0x10
#define ESP32_IO_BIT_CLEARING_EDGE_REGISTER 0
#define ESP32_IO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ESP32_IO_CAPTURE 0
#define ESP32_IO_DATA_WIDTH 3
#define ESP32_IO_DO_TEST_BENCH_WIRING 0
#define ESP32_IO_DRIVEN_SIM_VALUE 0
#define ESP32_IO_EDGE_TYPE "NONE"
#define ESP32_IO_FREQ 50000000
#define ESP32_IO_HAS_IN 1
#define ESP32_IO_HAS_OUT 0
#define ESP32_IO_HAS_TRI 0
#define ESP32_IO_IRQ -1
#define ESP32_IO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ESP32_IO_IRQ_TYPE "NONE"
#define ESP32_IO_NAME "/dev/esp32_io"
#define ESP32_IO_RESET_VALUE 0
#define ESP32_IO_SPAN 16
#define ESP32_IO_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * ir_rx configuration
 *
 */

#define ALT_MODULE_CLASS_ir_rx TERASIC_IRM
#define IR_RX_BASE 0x40
#define IR_RX_IRQ 1
#define IR_RX_IRQ_INTERRUPT_CONTROLLER_ID 0
#define IR_RX_NAME "/dev/ir_rx"
#define IR_RX_SPAN 4
#define IR_RX_TYPE "TERASIC_IRM"


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x11010c0
#define JTAG_UART_IRQ 4
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * motor_measure_left configuration
 *
 */

#define ALT_MODULE_CLASS_motor_measure_left motor_measure
#define MOTOR_MEASURE_LEFT_BASE 0x1101060
#define MOTOR_MEASURE_LEFT_IRQ -1
#define MOTOR_MEASURE_LEFT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_MEASURE_LEFT_NAME "/dev/motor_measure_left"
#define MOTOR_MEASURE_LEFT_SPAN 32
#define MOTOR_MEASURE_LEFT_TYPE "motor_measure"


/*
 * motor_measure_right configuration
 *
 */

#define ALT_MODULE_CLASS_motor_measure_right motor_measure
#define MOTOR_MEASURE_RIGHT_BASE 0x1101040
#define MOTOR_MEASURE_RIGHT_IRQ -1
#define MOTOR_MEASURE_RIGHT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_MEASURE_RIGHT_NAME "/dev/motor_measure_right"
#define MOTOR_MEASURE_RIGHT_SPAN 32
#define MOTOR_MEASURE_RIGHT_TYPE "motor_measure"


/*
 * mpu_i2c configuration
 *
 */

#define ALT_MODULE_CLASS_mpu_i2c i2c_opencores
#define MPU_I2C_BASE 0x1101000
#define MPU_I2C_IRQ 2
#define MPU_I2C_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MPU_I2C_NAME "/dev/mpu_i2c"
#define MPU_I2C_SPAN 32
#define MPU_I2C_TYPE "i2c_opencores"


/*
 * mpu_int configuration
 *
 */

#define ALT_MODULE_CLASS_mpu_int altera_avalon_pio
#define MPU_INT_BASE 0x1101080
#define MPU_INT_BIT_CLEARING_EDGE_REGISTER 0
#define MPU_INT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MPU_INT_CAPTURE 1
#define MPU_INT_DATA_WIDTH 1
#define MPU_INT_DO_TEST_BENCH_WIRING 0
#define MPU_INT_DRIVEN_SIM_VALUE 0
#define MPU_INT_EDGE_TYPE "RISING"
#define MPU_INT_FREQ 100000000
#define MPU_INT_HAS_IN 1
#define MPU_INT_HAS_OUT 0
#define MPU_INT_HAS_TRI 0
#define MPU_INT_IRQ 0
#define MPU_INT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MPU_INT_IRQ_TYPE "EDGE"
#define MPU_INT_NAME "/dev/mpu_int"
#define MPU_INT_RESET_VALUE 0
#define MPU_INT_SPAN 16
#define MPU_INT_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x1080000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "Qsys_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 300000
#define ONCHIP_MEMORY2_0_SPAN 300000
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sonic_distance_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sonic_distance_0 sonic_distance
#define SONIC_DISTANCE_0_BASE 0x38
#define SONIC_DISTANCE_0_IRQ -1
#define SONIC_DISTANCE_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SONIC_DISTANCE_0_NAME "/dev/sonic_distance_0"
#define SONIC_DISTANCE_0_SPAN 8
#define SONIC_DISTANCE_0_TYPE "sonic_distance"


/*
 * sw configuration
 *
 */

#define ALT_MODULE_CLASS_sw altera_avalon_pio
#define SW_BASE 0x0
#define SW_BIT_CLEARING_EDGE_REGISTER 0
#define SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_CAPTURE 0
#define SW_DATA_WIDTH 4
#define SW_DO_TEST_BENCH_WIRING 0
#define SW_DRIVEN_SIM_VALUE 0
#define SW_EDGE_TYPE "NONE"
#define SW_FREQ 50000000
#define SW_HAS_IN 1
#define SW_HAS_OUT 0
#define SW_HAS_TRI 0
#define SW_IRQ -1
#define SW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SW_IRQ_TYPE "NONE"
#define SW_NAME "/dev/sw"
#define SW_RESET_VALUE 0
#define SW_SPAN 16
#define SW_TYPE "altera_avalon_pio"


/*
 * sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys altera_avalon_sysid_qsys
#define SYSID_QSYS_BASE 0x11010b0
#define SYSID_QSYS_ID 0
#define SYSID_QSYS_IRQ -1
#define SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_NAME "/dev/sysid_qsys"
#define SYSID_QSYS_SPAN 8
#define SYSID_QSYS_TIMESTAMP 1516871287
#define SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x1101020
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 100000000
#define TIMER_0_IRQ 5
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 99999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * uart_bt configuration
 *
 */

#define ALT_MODULE_CLASS_uart_bt altera_up_avalon_rs232
#define UART_BT_BASE 0x11010b8
#define UART_BT_IRQ 3
#define UART_BT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_BT_NAME "/dev/uart_bt"
#define UART_BT_SPAN 8
#define UART_BT_TYPE "altera_up_avalon_rs232"

#endif /* __SYSTEM_H_ */
