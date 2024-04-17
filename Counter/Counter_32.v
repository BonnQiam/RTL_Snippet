module Counter_32(clk, rst, out);
	parameter n = 5;
    
    input rst,clk; // 复位与时钟信号
    output [n-1:0] out;
    wire [n-1:0] next;

    DFF #(n) count(clk, next, out);
    
    assign next = rst ? 0 : (out+1);
endmodule
