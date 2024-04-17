//---------------------------
//  任意宽度的 3 选 1 多路选择器，选择信号采用二进制信号
//---------------------------
module binary_mux_3 (
    a2,a1,a0,sb,b
);
    parameter  k = 1;
    input [k-1:0] a0,a1,a2; //输入信号
    input [1:0] sb; //二进制编码的选择信号
    output [k-1:0] b;
    wire [2:0] s;

    Dec_n_m #(2,3) d(sb,s); //通过译码器将二进制信号转化为独热码信号
    mux_3_case #(k) m(a2,a1,a0,s,b);//多路选择器选择输入

endmodule
