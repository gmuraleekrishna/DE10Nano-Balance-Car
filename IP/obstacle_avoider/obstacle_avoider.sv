module obstacle_avoider (
	output s_read,
	output s_write,
	output [31:0] s_writedata,
	input [31:0] s_readdata,
	output [2:0] s_address,
	output s_cs,
	input reset_n,
	input clk,
	output [31:0] motor_speed,
	output run
);


	`define SONIC_REG 3'h0 

	reg [1:0] state;
	reg [21:0] distance_measurement;


	assign s_write = 1'b0;

	always_ff @(posedge clk) begin
		s_cs = 1'b0;
		s_read = 1'b0;
		s_address = `SONIC_REG;
		s_read = 1'b1;
		s_cs = 1'b1;
		distance_measurement = s_readdata[21:0];
	end

	always_comb begin
		if (distance_measurement >= 1'd0 && distance_measurement < 15'd1000)
			run = 1'd0;
		else if (distance_measurement >= 15'd1000  && distance_measurement < 20'd100000) begin 
			motor_speed <= 32'd4500;
			run = 1'd1;
		end else if (distance_measurement >= 20'd100000) begin
			motor_speed <= 16'd3000;
			run = 1'd1;
		end else begin
			motor_speed <= 32'd1000;
			run = 1'd1;
		end
	end

endmodule