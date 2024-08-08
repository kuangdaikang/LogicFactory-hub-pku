start
anchor -set yosys
read_aiger -file /workspace/LogicFactory/demo/b1_comb.aig
write_aiger -file test_b1_comb.arch.aig

arch2logic
ntktype -tool abc -type strash -ntk aig

anchor -set abc
strash
balance
rewrite
read_liberty -file /workspace/LogicFactory/techlib/clean/sky130.lib
write_aiger -file test_b1_comb.logic.aig
write_dot -file test_b1_comb.logic.dot
map_asic
write_verilog -file test_b1_comb.v
anchor -set ieda
config -file /workspace/LogicFactory/config/layer_netlist/ieda/config.json
logic2netlist
init
sta
floorplan
placement
cts
routing
stop



