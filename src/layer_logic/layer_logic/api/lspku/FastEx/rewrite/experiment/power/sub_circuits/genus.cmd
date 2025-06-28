# Cadence Genus(TM) Synthesis Solution, Version 19.12-s121_1, built Dec  3 2019 15:07:17

# Date: Fri Sep 15 11:22:13 2023
# Host: dasys20-cw (x86_64 w/Linux 5.4.0-154-generic) (24cores*96cpus*2physical cpus*Intel(R) Xeon(R) Gold 6248R CPU @ 3.00GHz 36608KB)
# OS:   CentOS release 6.10 (Final)

read_hdl ./no_power_0001.v
set_attribute library /rshome/sunan.zou/nas/PowerAwareSynthesis/netlist/NanGate_15nm_OCL.lib
elaborate
report power
report area
report timing
q
