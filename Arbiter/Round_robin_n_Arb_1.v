module Round_robin_n_Arb_1 #(parameter NUM_REQ = 4)
(
  input                      clk,
  input                      rstn,
  input [NUM_REQ-1:0]        req,
  output [NUM_REQ-1:0]       gnt 
);

//reg [NUM_REQ-1:0]          hist_q, hist_d;
reg [NUM_REQ-1:0]          hist_q;

always@(posedge clk) begin
  if(!rstn) 
    hist_q <= {{NUM_REQ-1{1'b0}}, 1'b1};
  else
    if(|req)// |req mean any request is high
      hist_q <= {gnt[NUM_REQ-2:0], gnt[NUM_REQ-1]}; 
end

Arb_n_Input #(
  .NUM_REQ(NUM_REQ)
) arbiter(
  .req      (req),
  .gnt      (gnt),
  .base     (hist_q)
);

endmodule
