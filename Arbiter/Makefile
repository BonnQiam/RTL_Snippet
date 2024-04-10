# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Arb_4_LSB
#VERILOG_FILE = Arb_n_LSB
VERILOG_FILE = Arb_n_MSB

# Name of the testbench C++ file (without extension)
#TESTBENCH_FILE = tb_Arb_4_LSB
#TESTBENCH_FILE = tb_Arb_n_LSB
TESTBENCH_FILE = tb_Arb_n_MSB

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
#	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# for Arb_n_LSB / Arb_n_MSB
	verilator $(VERILATOR_FLAGS) -Gn=8  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
