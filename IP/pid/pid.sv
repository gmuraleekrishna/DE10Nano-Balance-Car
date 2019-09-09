module pid (
	input	clk,
	input reset_n,
	
   input	wire [7:0] process,
	output reg [1:0] direction,
	output reg [20:0] speed,
	output [7:0] LED
);

   reg signed [7:0] error;
	reg [3:0] linear_value;
	reg sign;
	
	
	linearizer lin (
		.process(process),
		.value(linear_value)
	);
	
	`define TARGET 4'd8
	`define KP 15'd1000
	`define STRAIGHT_SPEED 15'd3500
	
	`define STOP 2'd3
	`define LEFT 2'd1
	`define RIGHT 2'd2
	`define STRAIGHT 2'd0
 
	assign LED = speed;
	
	always@(posedge clk or negedge reset_n) begin
		if(!reset_n) begin
			error <= 0;
		end else begin
			if (`TARGET > linear_value) begin
				error = `TARGET - linear_value;
				sign = 1'b1;
			end else begin
				error = linear_value - `TARGET;
				sign = 1'b0;
			end
		end
	end
	
	always_ff @(*) begin
		if (linear_value == 4'd0) begin
			direction <= `STOP;
			speed <= 0;
		end else if (error == 4'd0 && sign == 1'b0) begin
			direction <= `STRAIGHT;
			speed <= `STRAIGHT_SPEED;
		end else if (sign == 1'b1) begin
			direction <= `LEFT;
			speed <= `KP*error;
		end else if (sign == 1'b0) begin
			direction <= `RIGHT;
			speed <= `KP*error;
		end else 
			direction <= `STOP;
	end
endmodule 