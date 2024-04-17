//--------------------------------
//任意宽度的 3选1 多路选择器，选择信号采用独热编码，采用case语句描述
//-------------------------------

module mux_3_case (
    a2,a1,a0,s,b
);
    parameter k = 1;
    input [k-1:0] a2,a1,a0; //输入信号
    input [2:0] s;//独热码选择信号
    output [k-1:0] b;//输出信号
    reg [k-1:0] b;

    always @(*) begin
        case (s)
            3'b001 : b=a0;
            3'b010 : b=a1;
            3'b100 : b=a2; 
            default: b={k{1'bx}};
        endcase
    end
endmodule
