module Auto_LFSR_8_ALGO (Y, Clock, Reset);
    parameter 	initial_state = 8'b1001_0001;

    /* verilator lint_off ASCRANGE */
    parameter 	[1: 8] Tap_Coefficient = 8'b1100_1111;
    /* verilator lint_off ASCRANGE */

    input 		Clock, Reset;

    /* verilator lint_off ASCRANGE */
    output 		[1: 8] Y;
    reg 		[1: 8] Y;
    /* verilator lint_off ASCRANGE */

    integer		Cell_ptr;
    
    always @  (posedge Clock)
    begin
        if (!Reset) 
            Y <= initial_state;		// Arbitrary initial state, 91h
        else begin 
            for (Cell_ptr = 2; Cell_ptr <= 8; Cell_ptr = Cell_ptr +1)
                if (Tap_Coefficient [8 - Cell_ptr + 1] == 1) 			
                    Y[Cell_ptr] <= Y[Cell_ptr -1]^ Y [8];
	            else
                    Y[Cell_ptr] <= Y[Cell_ptr -1];
	        Y[1] <= Y[8];
      end
    end
endmodule
