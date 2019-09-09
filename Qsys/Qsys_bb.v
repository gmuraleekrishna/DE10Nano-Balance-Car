
module Qsys (
	adc_ltc2308_0_conduit_end_CONVST,
	adc_ltc2308_0_conduit_end_SCK,
	adc_ltc2308_0_conduit_end_SDI,
	adc_ltc2308_0_conduit_end_SDO,
	clk_clk,
	dc_motor_left_conduit_end_motor_in1,
	dc_motor_left_conduit_end_motor_in2,
	dc_motor_left_conduit_end_pwm,
	dc_motor_right_conduit_end_motor_in1,
	dc_motor_right_conduit_end_motor_in2,
	dc_motor_right_conduit_end_pwm,
	direction_controller_0_conduit_end_led_readdata,
	direction_controller_0_conduit_leds_array_export,
	esp32_io_external_connection_export,
	ir_rx_conduit_end_export,
	motor_measure_left_conduit_end_ab,
	motor_measure_right_conduit_end_ab,
	mpu_i2c_export_scl_pad_io,
	mpu_i2c_export_sda_pad_io,
	mpu_int_external_connection_export,
	reset_reset_n,
	sonic_distance_0_conduit_end_echo,
	sonic_distance_0_conduit_end_trigger,
	sw_external_connection_export,
	uart_bt_external_interface_RXD,
	uart_bt_external_interface_TXD);	

	output		adc_ltc2308_0_conduit_end_CONVST;
	output		adc_ltc2308_0_conduit_end_SCK;
	output		adc_ltc2308_0_conduit_end_SDI;
	input		adc_ltc2308_0_conduit_end_SDO;
	input		clk_clk;
	output		dc_motor_left_conduit_end_motor_in1;
	output		dc_motor_left_conduit_end_motor_in2;
	output		dc_motor_left_conduit_end_pwm;
	output		dc_motor_right_conduit_end_motor_in1;
	output		dc_motor_right_conduit_end_motor_in2;
	output		dc_motor_right_conduit_end_pwm;
	output	[7:0]	direction_controller_0_conduit_end_led_readdata;
	inout	[7:0]	direction_controller_0_conduit_leds_array_export;
	input	[2:0]	esp32_io_external_connection_export;
	input		ir_rx_conduit_end_export;
	input	[1:0]	motor_measure_left_conduit_end_ab;
	input	[1:0]	motor_measure_right_conduit_end_ab;
	inout		mpu_i2c_export_scl_pad_io;
	inout		mpu_i2c_export_sda_pad_io;
	input		mpu_int_external_connection_export;
	input		reset_reset_n;
	input		sonic_distance_0_conduit_end_echo;
	output		sonic_distance_0_conduit_end_trigger;
	input	[3:0]	sw_external_connection_export;
	input		uart_bt_external_interface_RXD;
	output		uart_bt_external_interface_TXD;
endmodule
