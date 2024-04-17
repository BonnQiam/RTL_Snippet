//--------------------------------
//任意宽度的 4选1 多路选择器，选择信号采用独热编码，采用case语句描述
//-------------------------------

module Mux4 (
    a3,a2,a1,a0,s,b
);
    parameter k = 1;
    input [k-1:0] a3,a2,a1,a0; //输入信号
    input [3:0] s;//独热码选择信号
    output [k-1:0] b;//输出信号
    reg [k-1:0] b;

    always @(*) begin
        case (s)
            4'b0001 : b=a0;
            4'b0010 : b=a1;
            4'b0100 : b=a2; 
            4'b1000 : b=a3;
            default: b={k{1'bx}};
        endcase
    end
endmodule
