// 等值比较器
module Eq_Comparator (
    a,
    b,
    eq
);
    parameter k = 8;
    
    input [k-1:0] a,b;
    output eq;

    assign eq = (a==b);
endmodule
