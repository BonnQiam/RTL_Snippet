module Arb_n_LSB4 #(parameter REQ_WIDTH = 16) (
    req, gnt
);
    input  [REQ_WIDTH-1:0]     req;
	output [REQ_WIDTH-1:0]     gnt;
	
    assign gnt = req & (~(req-1));
endmodule
