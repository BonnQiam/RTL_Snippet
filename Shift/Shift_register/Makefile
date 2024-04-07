# Verilator flags
VERILATOR_FLAGS = -Wall

# Name of the Verilog file (without extension)
#VERILOG_FILE = Barrel_shift_register
#VERILOG_FILE = Shift_register_n
VERILOG_FILE = Shift_reg4

# Name of the testbench C++ file (without extension)
#TESTBENCH_FILE = tb_Barrel_shift_register
#TESTBENCH_FILE = tb_Shift_register_n
TESTBENCH_FILE = tb_Shift_reg4

# Compile Verilog to C++
verilate:
	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
#	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#for VERILOG_FILE = Shift_register_n
#	verilator $(VERILATOR_FLAGS) --cc -Gn=4 $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
