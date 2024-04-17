//----------------------------------------
// 任意宽度的 3 选 1 多路选择器，选择信号采用二进制信号
// 行为描述
//---------------------------------------

module binary_mux_3_case (
    a0,a1,a2,sb,b
);
    parameter  k = 1;
    input [k-1:0] a0,a1,a2; //输入信号
    input [1:0] sb; //二进制编码的选择信号
    output [k-1:0] b;
    reg [k-1:0] b;

    always @(*) begin
       case (sb)
           0        : b=a0;
           1        : b=a1;
           2        : b=a2; 
           default  : b = {k{1'bx}};
       endcase 
    end

endmodule
