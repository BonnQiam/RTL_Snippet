# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Dec_n_m
#VERILOG_FILE = decoder_16_4_assign
VERILOG_FILE = decoder_16_4_case

# Name of the testbench C++ file (without extension)

# for mux_using_if, mux_using_case, mux_using_assign
#TESTBENCH_FILE = tb_Dec_n_m
TESTBENCH_FILE = tb_decoder_16_4

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#	for Dec_n_m
#	verilator $(VERILATOR_FLAGS) -Gn=2 -Gm=4  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
