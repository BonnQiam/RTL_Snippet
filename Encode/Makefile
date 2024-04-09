# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Encoder_16_4_using_if
VERILOG_FILE = Encoder_16_4_using_case


# Name of the testbench C++ file (without extension)
#TESTBENCH_FILE = tb_Encoder_16_4_using_if
TESTBENCH_FILE = tb_Encoder_16_4_using_case

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
