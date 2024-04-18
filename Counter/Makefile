# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Counter_8
#VERILOG_FILE = Counter_32
#VERILOG_FILE = UDL_Counter_n_1
#VERILOG_FILE = UDL_Counter_n_2
#VERILOG_FILE = UDL_Counter_n_3
#VERILOG_FILE = Inc_Dec_By_3
VERILOG_FILE = Up_down_Counter_3

# Name of the testbench C++ file (without extension)

# for Counter_8, Counter_#2
#TESTBENCH_FILE = tb_Counter
#TESTBENCH_FILE = tb_UDL_Counter_n
#TESTBENCH_FILE = tb_Inc_Dec_By_3
TESTBENCH_FILE = tb_Up_down_Counter_3

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#	for Couter_32
#	verilator $(VERILATOR_FLAGS) -Gn=5 --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#	for UDL_Counter_n_1 / UDL_Counter_n_2 / UDL_Counter_n_3
#	verilator $(VERILATOR_FLAGS) -Gn=4 --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#	for Inc_Dec_By_3
#	verilator $(VERILATOR_FLAGS) -Gn=8 --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
