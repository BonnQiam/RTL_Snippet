//---------------------
//  任意宽度仲裁器 —— MSB 优先级最高
//---------------------
module Arb_n_MSB (
    r,g
);
    parameter n = 8;
    input   [n-1:0] r;
    output  [n-1:0] g;

    /* verilator lint_off UNOPTFLAT */
    wire    [n-1:0] c;
    /* verilator lint_off UNOPTFLAT */

    assign c ={
        1'b1,
        (~r[n-1:1] & c[n-1:1])
    };
    
    assign g = r&c;
endmodule
