# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Auto_LFSR_8_RTL
VERILOG_FILE = Auto_LFSR_8_ALGO


# Name of the testbench C++ file (without extension)
#TESTBENCH_FILE = tb_Auto_LFSR_8_RTL
TESTBENCH_FILE = tb_Auto_LFSR_8_ALGO

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
