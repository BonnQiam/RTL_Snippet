module Compare_n_CA #(parameter word_size = 32)(
    output A_gt_B, A_lt_B, A_eq_B,
    input [word_size -1: 0] A, B
);
    assign A_gt_B = (A >  B);
    assign A_lt_B = (A <  B);
    assign A_eq_B = (A == B);
endmodule
