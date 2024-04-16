module Round_robin_n_Arb_2 #(
 parameter N = 16
)(
input         clk,
input         rst,
input [N-1:0] req,
output[N-1:0] grant
);

wire [N-1:0] req_masked;
wire no_req_masked;
/* verilator lint_off UNOPTFLAT */
wire [N-1:0] mask_higher_pri_reqs;
wire [N-1:0] unmask_higher_pri_reqs;
/* verilator lint_off UNOPTFLAT */
wire [N-1:0] grant_masked;
wire [N-1:0] grant_unmasked;

reg [N-1:0] pointer_reg;

// Simple priority arbitration for masked portion, ref 'Arb_n_LSB2'
assign req_masked = req & pointer_reg;
assign mask_higher_pri_reqs[N-1:1] = mask_higher_pri_reqs[N-2: 0] | req_masked[N-2:0];
assign mask_higher_pri_reqs[0] = 1'b0;
assign grant_masked[N-1:0] = req_masked[N-1:0] & ~mask_higher_pri_reqs[N-1:0];

// Simple priority arbitration for unmasked portion, ref 'Arb_n_LSB2'
assign unmask_higher_pri_reqs[N-1:1] = unmask_higher_pri_reqs[N-2:0] | req[N-2:0];
assign unmask_higher_pri_reqs[0] = 1'b0;
assign grant_unmasked[N-1:0] = req[N-1:0] & ~unmask_higher_pri_reqs[N-1:0];

// Use grant_masked if there is any there, otherwise use grant_unmasked. 
assign no_req_masked = ~(|req_masked);
assign grant = ({N{no_req_masked}} & grant_unmasked) | grant_masked;

// Pointer update
always @ (posedge clk) begin
  if (rst) begin
    pointer_reg <= {N{1'b1}};
  end else begin
    if (|req_masked) begin // Which arbiter was used?
      pointer_reg <= mask_higher_pri_reqs;
    end else begin
      if (|req) begin // Only update if there's a req 
        pointer_reg <= unmask_higher_pri_reqs;
      end else begin
        pointer_reg <= pointer_reg ;
      end
    end
  end
end

endmodule
