module linearizer (
	input	wire [7:0] process,
	output reg [3:0] value
);

	always_ff @(*) begin
		case (process)
			8'b00000000: value <= 4'd0;
			8'b00000001: value <= 4'd1;
			8'b00000011: value <= 4'd2;
			8'b00000010: value <= 4'd3;
			8'b00000110: value <= 4'd4;
			8'b00000100: value <= 4'd5;
			8'b00001100: value <= 4'd6;
			8'b00001000: value <= 4'd7;
			8'b00011000: value <= 4'd8;
			8'b00010000: value <= 4'd9;
			8'b00110000: value <= 4'd10;
			8'b00100000: value <= 4'd11;
			8'b01100000: value <= 4'd12;
			8'b01000000: value <= 4'd13;
			8'b11000000: value <= 4'd14;
			8'b10000000: value <= 4'd15;
			default: value <= 4'd0;
		endcase 
	end 
endmodule 