//-----------------------------
// 基本（左移）移位寄存器
// rst —— 将 out设置为 0，否则out值左移
// sin 填充 LSB
//-----------------------------
module Shift_register_n(clk, rst, sin, out);
    parameter n=4 ;

    input clk, rst, sin ;
    output [n-1:0] out ;
    
    wire [n-1:0] next = rst ? {n{1'b0}}: {out[n-2:0] ,sin};
    
    DFF #(n)cnt (clk,next,out);
endmodule
