module mux_4_32_case (
    mux_out, 
    data_3, data_2, data_1, data_0, 
    select, 
    enable);
	
	output 	[31: 0] mux_out;
	input 	[31: 0] data_3, data_2, data_1, data_0;
	input 	[1:0] 	select;
	input 			enable;
	reg 	[31:0]	mux_int;
	
	assign mux_out = enable ? mux_int : 32'bz;
	
	always @ ( data_3 or data_2 or data_1 or data_0 or select) begin
	    case (select)
	      0:		mux_int = data_0;
	      1:		mux_int = data_1;
	      2:		mux_int = data_2;
	      3:		mux_int = data_3;
	      default:	mux_int = 32'bx;//可以在仿真中执行
	    endcase
	end
endmodule

