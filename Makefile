# Verilator flags
VERILATOR_FLAGS = -Wall

# Name of the Verilog file (without extension)
VERILOG_FILE = Comp_2_CA1

# Name of the testbench C++ file (without extension)
##TESTBENCH_FILE = testbench
TESTBENCH_FILE = tb

# Compile Verilog to C++
verilate:
	verilator $(VERILATOR_FLAGS) --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
