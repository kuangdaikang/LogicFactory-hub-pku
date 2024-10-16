start
anchor -tool yosys
read_aiger -file /home/niliwei/dev/LogicFactory/demo/b1_comb.aig
write_aiger -file test_b1_comb.arch.aig

arch2logic
anchor -tool abc
ntktype -tool abc -stat logic -type aig
update -n

strash
balance
rewrite
read_liberty -file /home/niliwei/dev/LogicFactory/techlib/clean/sky130.lib
write_aiger -file test_b1_comb.logic.aig
write_dot -file test_b1_comb.logic.dot
map_asic
write_verilog -file test_b1_comb.v

anchor -tool ieda
logic2netlist
config -file /home/niliwei/dev/LogicFactory/config/layer_netlist/ieda/config.json
init
sta
floorplan
placement
cts
routing
stop



