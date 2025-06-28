import os

for file in os.listdir('/home/zousunan/power_benchmark'):
    with open('/home/zousunan/power_benchmark/' + file, 'r') as f:
        with open('/home/zousunan/temp/' + "l"+file, 'w') as f1:
            for line in f.readlines():
                if line.find("module") == -1 or line.find("endmodule") != -1:
                    f1.write(line)
                else:
                    module_name_pos = line.split().index('module') + 1
                    c = line.split()
                    a = c[module_name_pos]
                    new_name = "l"+file[0: file.find('.')]
                    line = line.replace(a, new_name, 1)
                    f1.write(line)

with open('benchmarks/train_set/train_list_glitch.txt', 'w') as f:
    for file in os.listdir('benchmarks/train_set'):
        f.write(file+"\n")
'''

import gym
env = gym.make('gym_dev:dev-v0', lib_file="/home/zousunan/nas/PowerAwareSynthesis/netlist/gsc145nm.lib")
env.setup('benchmarks/test_set/adder.v')
env.reset()
env.step(4)
env.write('test_result.v', 'verilog')
env.stop()
'''

'''
with open('./network/trace_file', 'r') as file:
    lines = file.readlines()
    last = -1
    for original_line in lines:
        line = original_line.split()
        if int(line[1]) != last:
            # os.system("mv "+"/home/zousunan/nas/PowerAwareSynthesis/gym-genus/gym_genus/genus_script/PAS_map_max24851_"+line[0] + " /home/zousunan/nas/PowerAwareSynthesis/benchmarks/max_abc_trace/max_"+line[1])
            last = int(line[1])
            with open('./network/max_abc_trace.txt','a') as f:
                f.write(original_line)
                f.close()

    file.close()
'''
