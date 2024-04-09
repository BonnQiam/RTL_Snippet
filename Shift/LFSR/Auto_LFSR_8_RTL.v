module Auto_LFSR_8_RTL (Y, Clock, Reset);
    parameter 		    initial_state = 8'b1001_0001;
    
    //parameter [8: 1] 	Tap_Coefficient = 8'b1100_1111; 
    /* verilator lint_off ASCRANGE */
    parameter [1: 8] 	Tap_Coefficient = 8'b1100_1111; 
    /* verilator lint_off ASCRANGE */
    
    input 			Clock, Reset;
    //output [8: 1] 	Y;
    //reg	 [8: 1] 	Y;
    /* verilator lint_off ASCRANGE */
    output [1: 8] 	Y;
    reg	 [1: 8] 	Y;
    /* verilator lint_off ASCRANGE */
    
    always @  (posedge Clock) begin
        if (!Reset) 
            Y <= initial_state;	// Active-low reset to initial state
        else begin
            Y[1] <= Y[8];
            Y[2] <= Tap_Coefficient[7] ? Y[1] ^ Y[8] : Y[1];
            Y[3] <= Tap_Coefficient[6] ? Y[2] ^ Y[8] : Y[2];
            Y[4] <= Tap_Coefficient[5] ? Y[3] ^ Y[8] : Y[3];
            Y[5] <= Tap_Coefficient[4] ? Y[4] ^ Y[8] : Y[4];
            Y[6] <= Tap_Coefficient[3] ? Y[5] ^ Y[8] : Y[5];
            Y[7] <= Tap_Coefficient[2] ? Y[6] ^ Y[8] : Y[6];
            Y[8] <= Tap_Coefficient[1] ? Y[7] ^ Y[8] : Y[7];
        end
    end
endmodule
/*
In Verilog, both parameter [1:8] Tap_Coefficient and parameter [8:1] Tap_Coefficient define an 8-bit parameter named Tap_Coefficient, but they differ in the way they index the bits of the parameter.

- parameter [1:8] Tap_Coefficient: This declaration specifies a parameter where the most significant bit (MSB) is indexed as 1, and the least significant bit (LSB) is indexed as 8. This means that in memory, the bits are ordered from 1 to 8, with bit 1 being the MSB and bit 8 being the LSB. For example, Tap_Coefficient[1] refers to the most significant bit, and Tap_Coefficient[8] refers to the least significant bit.

- parameter [8:1] Tap_Coefficient: Conversely, this declaration specifies a parameter where the MSB is indexed as 8, and the LSB is indexed as 1. This means that in memory, the bits are ordered from 8 to 1, with bit 8 being the MSB and bit 1 being the LSB. For example, Tap_Coefficient[8] refers to the most significant bit, and Tap_Coefficient[1] refers to the least significant bit.

In terms of the actual data stored in memory, both declarations result in the same 8-bit binary value 1100_1111. The difference lies only in how you index and reference the individual bits within the parameter.
*/
