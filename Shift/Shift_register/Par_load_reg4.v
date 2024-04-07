module Par_load_reg4 (Data_out, Data_in, load, clock, reset);
    input   [3: 0] 	Data_in;
    input 			load, clock, reset;
    output 	[3: 0] 	Data_out;
    reg 	[3: 0]  Data_out;
    
    always @  (posedge reset or posedge clock)
    begin
        if (reset == 1'b1) 		
            Data_out <= 4'b0;
        else if (load == 1'b1) 	
            Data_out <= Data_in;
    end
endmodule
