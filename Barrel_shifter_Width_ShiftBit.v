module Barrel_shifter_Width_ShiftBit (
    n,
    a,
    b
);
    parameter width          = 8;
    parameter shifter_bit    = 3;

    input  [width-1:0]      a;
    input  [shifter_bit-1:0] n;
    output [width-1:0]      b;

    //wire [2*width-2:0] x = a << n;
    wire [2*width-2:0] x = {{width-1{1'b0}},a} << n;
    assign b = x[width-1:0] | {1'b0, x[2*width-2:width]};
endmodule
