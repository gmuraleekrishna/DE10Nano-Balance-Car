module direction_controller (
 input clk, // clock
 input reset_n, // reset
 inout tri [7:0] leds_array, // reflectance sensor inout
 output left_motor,
 output right_motor
 );
 
 reg [7:0] direction_command;

 ledsarray ledsarray1 (
	 .clk(clk),
	 .leds_array(leds_array),
	 .direction_command(direction_command),
	 .reset_n(reset_n)
 );


direction_control dir_ctrl (
	 .direction_command(~direction_command),
	 .left_motor(left_motor),
	 .right_motor(right_motor),
	 .clk(clk),
	 .reset_n(reset_n)
 );
endmodule