//数值比较器的行为描述
module MagComp_b(a, b,gt) ;
	parameter k=8 ;
	input[k-1:0] a, b ;
	output gt ;

	assign  gt = (a > b);
endmodule
