# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = mux_using_if
#VERILOG_FILE = mux_using_case
#VERILOG_FILE = mux_using_assign
#VERILOG_FILE = mux_4_32_case
#VERILOG_FILE = mux_4_32_if
#VERILOG_FILE = mux_4_32_CA
#VERILOG_FILE = mux_3_assign
#VERILOG_FILE = mux_3_case

#VERILOG_FILE = binary_mux_3_case
VERILOG_FILE = binary_mux_3

# Name of the testbench C++ file (without extension)

# for mux_using_if, mux_using_case, mux_using_assign
#TESTBENCH_FILE = tb_mux
#TESTBENCH_FILE = tb_mux_4_32
#TESTBENCH_FILE = tb_mux_3
TESTBENCH_FILE = tb_binary_mux_3

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
#	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#	for mux_3_assign / mux_3_case / binary_mux_3_case / binary_mux_3
	verilator $(VERILATOR_FLAGS) -Gk=1  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
