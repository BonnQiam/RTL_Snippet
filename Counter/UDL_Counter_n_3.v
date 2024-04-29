module UDL_Counter_n_3(clk,rst,up,down,load,in,out) ;
    parameter n= 4 ;
    input clk,rst, up,down,load ;
    input [n-1:0] in ;
    output [n-1:0] out ;
    wire [n-1:0] next, outpm1 ;
    
    DFF #(n) count (clk,next, out) ;//寄存器输出
    
    assign outpm1 = out+{{n-1{down}},1'b1};// out-1 when down=1, out+1 when up=1
    
    Mux4 #(n) mux (out, 
              in,
				      outpm1,
				      {n{1'b0}},//以上均为输入
		          {
		            (~rst & ~up & ~down & ~load),
		            (~rst & load),
		            (~rst & (up | down)),
                rst 
		          },//译码单元
	            next) ; // Mux 输出
endmodule
