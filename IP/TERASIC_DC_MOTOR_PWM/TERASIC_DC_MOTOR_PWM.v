// TERASIC_DC_MOTOR_PWM.v

// This file was auto-generated as a prototype implementation of a module
// created in component editor.  It ties off all outputs to ground and
// ignores all inputs.  It needs to be edited to make it do something
// useful.
// 
// This file will not be automatically regenerated.  You should check it in
// to your version control system if you want to keep it.

`timescale 1 ps / 1 ps
module TERASIC_DC_MOTOR_PWM (
		input  wire        clk,          //          clock.clk
		input  wire        reset_n,      //          reset.reset_n
		output wire        PWM,          //  conduit_end_1.pwm
		output wire        DC_MOTOR_IN1, //               .motor_in1
		output wire        DC_MOTOR_IN2, //               .motor_in2
		input  wire        s_cs,         // avalon_slave_0.beginbursttransfer
		input  wire [1:0]  s_address,    //              s.address
		input  wire        s_write,      //               .write
		input  wire [31:0] s_writedata,  //               .writedata
		input  wire        s_read,       //               .read
		output wire [31:0] s_readdata    //               .readdata
	);

	// TODO: Auto-generated HDL template

	assign DC_MOTOR_IN2 = 1'b0;

	assign PWM = 1'b0;

	assign DC_MOTOR_IN1 = 1'b0;

	assign s_readdata = 32'b00000000000000000000000000000000;

endmodule
