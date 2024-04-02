module Comp_2_RTL(
    output reg A_lt_B,A_gt_B,A_eq_B, 
    input A1,A0,B1,B0
);
    always @(A0,A1,B0,B1) begin
        A_lt_B = ({A1,A0} <  {B1,B0});
        A_gt_B = ({A1,A0} >  {B1,B0});
        A_eq_B = ({A1,A0} == {B1,B0});
    end
endmodule
