module UDL_Counter_n_2(clk, rst, up, down, load, in, out);
    parameter n= 4;
    input clk,rst,up, down,load;
    input [n-1:0] in;
    output [n-1 :0] out;
    wire [n-1:0] outpm1;
    reg [n-1:0] next;
    
    DFF#(n) count (clk, next, out) ;
    
    assign outpm1 = out + {{n-1{~up}},1'b1};
    
    always@(* ) begin
        /*
        casex( {rst, up,down,load})
            4'b1xxx : next = {n{1'b0}};
            4'b01xx : next = outpm1 ;
            4'b001x : next = outpm1 ;
            4'b0001 : next = in;
            default : next = out ;
        endcase
        */
        casez( {rst, up,down,load})
            4'b1??? : next = {n{1'b0}};
            4'b01?? : next = outpm1;
            4'b001? : next = outpm1;
            4'b0001 : next = in;
            default : next = out;
        endcase
    end
endmodule
