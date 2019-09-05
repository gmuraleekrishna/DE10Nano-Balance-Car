module direction_control (
	input logic [7:0] direction_command, // reflectance sensor binary output
	input logic clk,
	input logic reset_n,
	output logic left_motor,
	output logic right_motor // motor binary signals
 );

// Direction variables.

logic straight, turnRight, turnLeft, stop;

// Output motor directin bianry signals.

always_ff@(posedge clk)
begin

 if(straight)begin
	 left_motor <= 1'b1;
	 right_motor <= 1'b1;
 end
 else if(turnRight)begin
	right_motor <= 1'b0;
	left_motor <= 1'b1;
 end
 else if(turnLeft)begin
	right_motor <= 1'b1;
	left_motor <= 1'b0;
 end
 else if(stop) begin
	right_motor <= 1'b0;
	left_motor <= 1'b0;
 end
 else begin
	right_motor <= right_motor;
	left_motor <= left_motor;
 end
end

// Output the direction based on the reflectance sensor outputs.
always_comb begin
 if (direction_command == 8'b00011000 || direction_command == 8'b00010000 || direction_command ==
8'b00001000)
 begin
 straight = 1;
 turnRight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00001100 || direction_command == 8'b00000100 || direction_command == 8'b00001000)
 begin
	 turnRight = 1;
	 straight = 0;
	 turnLeft = 0;
	 stop = 0;
 end
 else if (direction_command == 8'b00000110 || direction_command == 8'b00000100 || direction_command == 8'b00000010 )
 begin
	 turnRight = 1;
	 straight = 0;
	 turnLeft = 0;
	 stop = 0;
 end
 else if (direction_command == 8'b00000011)
 begin
 turnRight = 1;
 straight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00000001)
 begin
 turnRight = 1;
 straight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00110000 || direction_command == 8'b00010000 || direction_command ==
8'b00100000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else if (direction_command == 8'b01100000 || direction_command == 8'b00100000 || direction_command ==
8'b01000000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else if (direction_command == 8'b11000000 || direction_command == 8'b01000000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else if (direction_command == 8'b10000000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 // 3 SENSORS ENGAGED
 else if (direction_command == 8'b00011100)
 begin
 straight = 1;
 turnRight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00001110)
 begin
 turnRight = 1;
 straight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00000111)
 begin
 turnRight = 1;
 straight = 0;
 turnLeft = 0;
 stop = 0;
 end
 else if (direction_command == 8'b00111000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else if (direction_command == 8'b01110000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else if (direction_command == 8'b11100000)
 begin
 turnLeft = 1;
 turnRight = 0;
 straight = 0;
 stop = 0;
 end
 else
 begin
 turnLeft = 0;
 turnRight = 0;
 straight = 0;
 stop = 1;
 end
end
endmodule 