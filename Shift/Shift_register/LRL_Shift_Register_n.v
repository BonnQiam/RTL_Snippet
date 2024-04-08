//-------------------
//具有载入功能的左移/右移移位寄存器
//-------------------
module LRL_Shift_Register_n(
    clk, rst, 
    left,right,load,
    sin,in,out);

	parameter n =4 ;
    
    input clk, rst;
    input left, right, load;
    input sin;
    input [n-1:0] in;
    output [n-1:0] out;
    reg [n-1:0] next;
    
    DFF #(n) cnt (clk,next,out) ;
    
    always@(*) begin
        /* verilator lint_off CASEX */
        casex({rst, left ,right ,load})
            4'b1xxx: next = 0;//复位
            4'b01xx: next = {out[n-2:0],sin} ; //左移
            4'b001x: next = {sin,out[n-1:1]} ; //右移
            4'b0001: next = in ;//载入
            default: next = out ;//保持
        endcase
        /* verilator lint_off CASEX */
    end
endmodule
