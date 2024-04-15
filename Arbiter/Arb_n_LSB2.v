module Arb_n_LSB2 #(parameter REQ_WIDTH = 16)(
    req, gnt
);
    input [REQ_WIDTH-1:0] req;
    output [REQ_WIDTH-1:0] gnt;
    
    /* verilator lint_off UNOPTFLAT */
    wire [REQ_WIDTH-1:0] pre_req;
    /* verilator lint_off UNOPTFLAT */

    assign pre_req[0] = 1'b0;
    assign pre_req[REQ_WIDTH-1:1] = req[REQ_WIDTH-2:0] | pre_req[REQ_WIDTH-2:0];
    assign gnt = req & ~pre_req;
endmodule
/*
module prior_arb #(parameter REQ_WIDTH = 16)(
	input [REQ_WIDTH-1:0]     req,
	output [REQ_WIDTH-1:0]    gnt
);
	logic [REQ_WIDTH-1:0]   pre_req;
	
	assign pre_req[0] = 1'b0;
	assign preq_req[REQ_WIDTH-1:1] = req[REQ_WIDTH-2:0] | pre_req[REQ_WIDTH-2:0];
	assign gnt = req & ~pre_req;
endmodule
*/
