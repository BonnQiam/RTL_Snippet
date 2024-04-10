//---------------------
//  任意宽度仲裁器 —— LSB 优先级最高
//---------------------
//实现原理参考多位仲裁器的实现
module Arb_n_LSB (
    r,g
);
    parameter n = 8;
    input   [n-1:0] r;
    output  [n-1:0] g;

    /* verilator lint_off UNOPTFLAT */
    wire    [n-1:0] c;
    /* verilator lint_off UNOPTFLAT */
    
    assign c = {
        (~r[n-2:0] & c[n-2:0]),
        1'b1
    };

    assign g = r&c;
endmodule
