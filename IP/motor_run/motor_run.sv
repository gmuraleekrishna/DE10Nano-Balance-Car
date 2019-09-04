module motor_run(
	input	clk,
	input	reset_n,
	output s_cs,
	output [3:0] s_address,
	output s_write,
	output s_read,
	output [31:0] s_writedata,
	input waitrequest
);

	`define REG_TOTAL_DUR 4'h0
	`define REG_HIGH_DUR	4'h1
	`define REG_CONTROL	4'd2


	assign s_read = 1'b0;  
	reg [2:0] state;
	
	always_ff @(posedge clk) begin
		case(state)
			3'd0: begin // high dur
				s_cs = 1'b0;
				s_write = 1'b0;
				s_writedata = 31'd3500;
				s_address = `REG_HIGH_DUR;
				s_write = 1'b1;
				s_cs = 1'b1;
			end
			3'd2: // total dur
			begin
				s_cs = 1'b0;
				s_write = 1'b0;
				s_writedata = 31'd7000;
				s_address = `REG_TOTAL_DUR;
				s_write = 1'b1;
				s_cs = 1'b1;
			end
			3'd4: begin
				s_cs = 1'b0;
				s_write = 1'b0;
				s_writedata = {29'b0, 1'b0, 1'b1, 1'b1}; // 29'd0, motor_fast_decay, motor_forward, motor_go
				s_address =`REG_CONTROL;
				s_write = 1'b1;
				s_cs = 1'b1;
			end
			
		endcase
	end

	always_ff @(posedge clk or negedge reset_n) begin
		if(~reset_n) state <= 3'd0;
		else if(state == 3'd0) state <= 3'd1;
		else if(state == 3'd1) state <= 3'd2;
		else if(state == 3'd2) state <= 3'd3;
		else if(state == 3'd3) state <= 3'd4;
		else state <= state;
	end
endmodule 