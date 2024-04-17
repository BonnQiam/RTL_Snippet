// Recommend that it is better style to use casez, and '?' in place of 'x' s in verilator
module Counter_8 (clk,rst,out) ;
	input rst, clk ;//复位和时钟信号
	output [2:0] out ;
	reg[2:0]next;
	
	DFF #(3) count(clk, next, out);

	always@(*) begin
		//casex( {rst,out})
		//4'b1xxx: next = 0;
        casez( {rst,out})  
			4'b1???: next = 0;
			4'd0   : next = 1;
			4'd1   : next = 2;
			4'd2   : next = 3;
			4'd3   : next = 4;
			4'd4   : next = 5;
			4'd5   : next = 6;
			4'd6   : next = 7;
			4'd7   : next = 0;
			default : next = 0;
		endcase
	end
endmodule
