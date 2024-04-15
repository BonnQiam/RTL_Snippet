module Arb_n_LSB1 #(parameter REQ_WIDTH = 16)(
    req, grant  
);  
    input [REQ_WIDTH-1:0] req;
    output [REQ_WIDTH-1:0] grant;
    reg [REQ_WIDTH-1:0] grant;

    reg [REQ_WIDTH-1:0] pre_req;
    integer i;

    always @* begin
        pre_req[0] = req[0];
        grant[0] = req[0];
        for (i = 1; i < REQ_WIDTH; i = i + 1) begin
            grant[i] = req[i] & ~pre_req[i-1];  // current req & no higher priority request
            pre_req[i] = req[i] | pre_req[i-1]; // or all higher priority requests
        end
    end
endmodule
/*
module Arb_n_LSB1 #(parameter REQ_WIDTH = 16)(
	input  logic  [REQ_WIDTH-1:0] req,
	output logic  [REQ_WIDTH-1:0] grant
);
	logic [REQ_WIDTH-1:0] pre_req;
	
	always_comb begin
		pre_req[0] = req[0];
		grant[0] = req[0];
		for (int i = 1; i < REQ_WIDTH; i = i + 1) begin
			grant[i] = req[i] & !pre_req[i-1];  // current req & no higher priority request
			pre_req[i] = req[i] | pre_req[i-1]; // or all higher priority requests
		end
	end
endmodule
*/
