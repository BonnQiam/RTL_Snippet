# Verilator flags
VERILATOR_FLAGS = -Wall

#VERILOG_FILE = Arb_4_LSB
#VERILOG_FILE = Arb_n_LSB1
#VERILOG_FILE = Arb_n_LSB2
#VERILOG_FILE = Arb_n_LSB3
#VERILOG_FILE = Arb_n_LSB4
#VERILOG_FILE = Arb_n_MSB
#VERILOG_FILE = Arb_n_Input

#VERILOG_FILE = Round_robin_n_Arb_1
VERILOG_FILE = Round_robin_n_Arb_2

# Name of the testbench C++ file (without extension)
#TESTBENCH_FILE = tb_Arb_4_LSB
#TESTBENCH_FILE = tb_Arb_n_LSB1
#TESTBENCH_FILE = tb_Arb_n_LSB2
#TESTBENCH_FILE = tb_Arb_n_LSB3
#TESTBENCH_FILE = tb_Arb_n_LSB4
#TESTBENCH_FILE = tb_Arb_n_MSB
#TESTBENCH_FILE = tb_Arb_n_Input

#TESTBENCH_FILE = tb_Round_robin_n_Arb_1
TESTBENCH_FILE = tb_Round_robin_n_Arb_2


# Compile Verilog to C++
verilate:
#	verilator $(VERILATOR_FLAGS) --trace --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp
#	verilator $(VERILATOR_FLAGS)  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# for Arb_n_LSB3 / Arb_n_MSB
#	verilator $(VERILATOR_FLAGS) -Gn=8  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# for Arb_n_LSB1 / Arb_n_LSB2 / Arb_n_LSB4
#	verilator $(VERILATOR_FLAGS) -GREQ_WIDTH=16  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# for Arb_n_Input / Round_robin_n_Arb_1
#	verilator $(VERILATOR_FLAGS) -GNUM_REQ=4  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# for Round_robin_n_Arb_2
	verilator $(VERILATOR_FLAGS) -GN=4  --cc $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
