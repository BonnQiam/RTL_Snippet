//宽度为 4 位的仲裁器 —— LSB的优先级最高
module Arb_4_LSB (
    r,g
);
    input [3:0] r;
    output [3:0] g;
    reg [3:0] g;

    always @(*) begin
        /* verilator lint_off CASEX */
        casex (r)
            4'b0000     : g=4'b0000;
            4'bxxx1     : g=4'b0001;
            4'bxx10     : g=4'b0010;
            4'bx100     : g=4'b0100;
            4'b1000     : g=4'b1000; 
            default     : g=4'hx; 
        endcase
        /* verilator lint_off CASEX */
    end
endmodule
