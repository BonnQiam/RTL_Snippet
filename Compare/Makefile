# Verilator flags
VERILATOR_FLAGS = -Wall

# Name of the Verilog file (without extension)
##VERILOG_FILE = Comp_2_CA1
##VERILOG_FILE = Comp_2_CA2
#VERILOG_FILE = Compare_n_CA
#VERILOG_FILE = Comp_2_RTL
#VERILOG_FILE = Comp_2_algo

#VERILOG_FILE = MagComp_b
VERILOG_FILE = Eq_Comparator

# Name of the testbench C++ file (without extension)
##TESTBENCH_FILE = tb1_Comp_2_CA1
##TESTBENCH_FILE = tb2_Comp_2_CA1
##TESTBENCH_FILE = tb_Comp_2_CA2
#TESTBENCH_FILE = tb_Compare_n_CA
#TESTBENCH_FILE = tb_Comp_2_RTL
#TESTBENCH_FILE = tb_Comp_2_algo

#TESTBENCH_FILE = tb_MagComp_b
TESTBENCH_FILE = tb_Eq_Comparator

# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#   for VERILOG_FILE = Compare_n_CA
#	verilator $(VERILATOR_FLAGS) --cc -Gword_size=64 $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

#   for VERILOG_FILE = MagComp_b / Eq_Comparator
	verilator $(VERILATOR_FLAGS) --cc -Gk=8 $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
