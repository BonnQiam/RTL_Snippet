//------------------------------------------------------
// 任意宽度的 3选1 多路选择器，选择信号采用独热编码，其设计原理是基于与门、或门来实现多路选择器
//-------------------------------------------------------

module mux_3_assign (
    a2,a1,a0,s,b
);
    parameter k = 1;
    input [k-1:0] a2,a1,a0; //输入信号
    input [2:0] s;//独热码选择信号
    output [k-1:0] b;//输出信号

    /* 
    为了将选择信号形如 s[0]，连接到宽度为 k 的与门上，
    就必须复制一个 k 位的信号（通过复制运算符）
    */
    assign b = ({k{s[2]}} & a2) |
                ({k{s[1]}} & a1) |
                ({k{s[0]}} & a0);
endmodule
