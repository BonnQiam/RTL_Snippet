//  if Data_reg is a 4-bit vector [D3, D2, D1, D0], Data_reg[3:1] would select [D3, D2, D1].
//  if Data_reg is a 4-bit vector [D3, D2, D1, D0], Data_reg[1:3] would select [D1, D2, D3].
// shift right
module Shift_reg4 (Data_out, Data_in, clock, reset);
  output 	    Data_out;
  input 		Data_in, clock, reset;
  reg 	[3: 0] 	Data_reg;

  assign 	Data_out = Data_reg[0];

  //always @  (negedge reset or posedge clock)
  always @  (posedge clock)			
    begin 
      if (reset == 1'b0)  	
	      Data_reg <= 4'b0;
      else 		
	      Data_reg <= {Data_in, Data_reg[3:1]};
    end
endmodule
