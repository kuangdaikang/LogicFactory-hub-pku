create_clock -period 10 -name vclk
set_input_delay 0 [all_inputs] -clock vclk
set_output_delay 0 [all_outputs] -clock vclk
