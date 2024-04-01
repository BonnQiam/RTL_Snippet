module Comp_2_CA1 (
    output A_lt_B,A_gt_B,A_eq_B, 
    input A1,A0,B1,B0
);
    assign A_lt_B = ({A1,A0} <  {B1,B0});
    assign A_gt_B = ({A1,A0} >  {B1,B0});
    assign A_eq_B = ({A1,A0} == {B1,B0});
endmodule
