module Comp_2_algo (
    output reg A_lt_B, A_gt_B,A_eq_B, 
    input [1:0]A, B
);
    always @(A,B)//电平敏感行为
    begin
        A_lt_B = 0;
        A_gt_B = 0;
        A_eq_B = 0;
        if (A== B)
            A_eq_B =1;//注意:圆括号是必需的
    	else if (A>B)
            A_gt_B= 1;
        else
            A_lt_B=1;
    end
endmodule
