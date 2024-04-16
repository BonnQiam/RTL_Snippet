//---------------------------
//  4线-2线编码器（数据流描述）
//--------------------------

module Encoder_4_2 (
    a,b
);
    /* verilator lint_off UNUSEDSIGNAL */
    input [3:0] a;
    /* verilator lint_off UNUSEDSIGNAL */
    output [1:0] b;

    assign b = {
                a[3] | a[2],
                a[3] | a[1]
                };
endmodule
