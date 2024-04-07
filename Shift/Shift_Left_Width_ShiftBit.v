module Shift_Left_Width_ShiftBit (
    n,
    a,
    b
);
    parameter width          = 8;
    parameter shifter_bit    = 3;

    input  [width-1:0]          a;
    input  [shifter_bit-1:0]    n;
    output [2*width-2:0]        b;

    assign b = {{width-1{1'b0}},a} << n;
endmodule

