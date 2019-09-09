module direction_controller (
	input clk, // clock
	input reset_n, // reset
	inout tri [7:0] leds_array, // reflectance sensor inout
	output left_motor,
	output right_motor,
	output [20:0] right_motor_speed,
	output [20:0] left_motor_speed,
	output [7:0] LED
 );
 
	reg [7:0] direction_command;
	reg [1:0] direction;
	wire [20:0] speed;

	ledsarray ledsarray1 (
		 .clk(clk),
		 .leds_array(leds_array),
		 .direction_command(direction_command),
		 .reset_n(reset_n)
	);

	pid pid1 (
		.clk(clk),
		.reset_n(reset_n),
		.process(~direction_command),
		.direction(direction),
		.speed(speed),
		.LED(LED)
	);
	
	assign left_motor_speed = speed;
	assign right_motor_speed = speed;
	
	direction_control dir_ctrl (
		 .direction_command(direction),
		 .left_motor(left_motor),
		 .right_motor(right_motor),
		 .clk(clk),
		 .reset_n(reset_n)
	);
endmodule