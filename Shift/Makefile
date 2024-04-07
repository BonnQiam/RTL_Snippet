# Verilator flags
VERILATOR_FLAGS = -Wall

VERILOG_FILE = Shift_Left_Width_ShiftBit
#VERILOG_FILE = Barrel_shifter_Width_ShiftBit


# Name of the testbench C++ file (without extension)
TESTBENCH_FILE = tb_Shift_Left_Width_ShiftBit
#TESTBENCH_FILE = tb_Barrel_shifter_Width_ShiftBit

# Compile Verilog to C++
verilate:
#   for VERILOG_FILE = Barrel_shifter_Width_ShiftBit / Shift_Left_Width_ShiftBit
	verilator $(VERILATOR_FLAGS) --cc -Gwidth=8 -Gshifter_bit=3 $(VERILOG_FILE).v --exe $(TESTBENCH_FILE).cpp

# Compile and run simulation
sim: verilate
	cd obj_dir && make -j -f V$(VERILOG_FILE).mk V$(VERILOG_FILE)

# Clean up
clean:
	rm -rf obj_dir *.log *.vcd
