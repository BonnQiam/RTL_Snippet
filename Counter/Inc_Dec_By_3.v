module Inc_Dec_By_3(clk, rst, inc, dec,out) ;
    parameter n=8 ;
    input clk, rst,inc, dec ;
    output [n-1:0] out ;
    reg [n-1:0] next ;
    
    DFF #(n) sr(clk,next, out) ;
    
    wire [n-1:0] outpm3 = out +(dec ? (~2): 3 ); // when dec=1, out=out-3; when inc=1, out=out+3
                                                 // ~2 means -3, 3 means +3
    
    always @(*) begin
        /*
        casex( {rst ,inc , dec })
        casez( {rst ,inc, dec})
            3'b1XX: next =0;//复位
            3'b010: next = outpm3 ;//加计数
            3'b001: next = outpm3 ;//减计数
            3'b000: next = out ;//保持
            default: next = {n{1'bX}};
        endcase
        */
        casez( {rst ,inc, dec})
            3'b1??: next =0;//复位
            3'b010: next = outpm3 ;//加计数
            3'b001: next = outpm3 ;//减计数
            3'b000: next = out ;//保持
            default: next = {n{1'b0}};
        endcase
    end
endmodule
