module Varshift_n (clk, rst, sh_amount, sin, out) ;
    parameter n=8 ;

    input clk, rst ;

    input [1:0] sh_amount;//shift left bit
    input [2:0] sin ;
    output [n-1:0] out;
    
    /* verilator lint_off UNUSEDSIGNAL */
    wire [n-1+3:0] next_width = rst ? 0 : {out,sin} >> (3-sh_amount);
    /* verilator lint_off UNUSEDSIGNAL */
    //wire [n-1:0] next = next_width[3+n-1:3] ;
    wire [n-1:0] next = next_width[n-1:0] ;

    DFF#(n) sr(clk, next, out) ;
endmodule
