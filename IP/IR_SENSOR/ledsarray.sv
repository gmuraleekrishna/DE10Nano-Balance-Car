module ledsarray( 
	inout tri [7:0] leds_array, // reflectance sensor inout
	output logic [7:0] direction_command, // reflectance sensor binary signal
	input logic reset_n, clk); // reset and clock

	enum logic [2:0] // enumeration for the states
	{
		ledsout, // set pins as output
		ledsin, // set pins as input
		wait1, // wait 10 us for sensors to charge
		wait2, // wait x amount before reading sensors
		test // read sensors
	} state, state_next;
	enum logic [1:0]
	{
		infinite,
		in,
		out
	} direction; // enum for pin direction, and loop the program forever

	logic signed [31:0] count1, count2; // count register

	parameter tenu = 500; // 10us dealy for sensors to chrage up. (500 clk cycles)
	parameter hunu = 20000; // 100us dealy before checking sensors. (5000 clk cycles)

	// Register

	always_ff@(posedge clk) begin
		if (state == ledsout)begin
		leds_array <= '1; // set pins high
		direction = out;
	end
	else if (state == ledsin)begin
		leds_array <= 'z; // read from pins
		direction = in;
	end

	if (state == wait1) // 10us counter
		count1 <= count1 + 1'b1;
	else
		count1 <= 0; // if not counting counter should remain at zero

	if (state == wait2) // 100us counter
		count2 <= count2 + 1'b1;
	else
		count2 <= 0; // if not counting counter should remain at zero

	if (state == test) begin
		direction = infinite;

	// Tell the posiotion of each sensor (if on the line or not)

	if(leds_array[0] ==1'b1)
		direction_command[0] <= 1'b1;
	else
		direction_command[0] <= 1'b0;

	if(leds_array[1] ==1'b1)
		direction_command[1] <= 1'b1;
	else
		direction_command[1] <= 1'b0;

	if(leds_array[2] ==1'b1)
		direction_command[2] <= 1'b1;
	else
		direction_command[2] <= 1'b0;

	if(leds_array[3] ==1'b1)
		direction_command[3] <= 1'b1;
	else
		direction_command[3] <= 1'b0;

	if(leds_array[4] ==1'b1)
		direction_command[4] <= 1'b1;
	else
		direction_command[4] <= 1'b0;

	if(leds_array[5] ==1'b1)
		direction_command[5] <= 1'b1;
	else
		direction_command[5] <= 1'b0;

	if(leds_array[6] ==1'b1)
		direction_command[6] <= 1'b1;
	else
		direction_command[6] <= 1'b0;

	if(leds_array[7] ==1'b1)
		direction_command[7] <= 1'b1;
	else
		direction_command[7] <= 1'b0;
end


end

	// Controller register

	always_ff@(posedge clk)
	begin
		state <= state_next;
	end

	always_comb begin
		state_next = state;

		if ((reset_n == 0) || (direction == infinite))
			state_next = ledsout;
		if (direction == out)
			state_next = wait1;
		if (count1 >= tenu)
			state_next = ledsin;
		if (direction == in)
			state_next = wait2;
		if (count2 >= hunu)
			state_next = test;
	end

endmodule 