//
// Created by zephyr on 7/17/2023.
//
#include "../exact_synthesis/exact.h"
#include "netlist.h"

int main(int argc, char** argv) {
    NET::Netlist netlist;
    std::string test_case = std::string(argv[1]) + ".blif";
    NET::read_blif("../experiments/power/test_set/"+test_case, netlist);
    std::cout<<"Finish netlist loading\n";
    NET::lut_rewrite_power(netlist, "../experiments/power/optimal_library_expand.txt");
    //NET::lut_rewrite(netlist, "../experiments/beswac/202308/optimal_library.txt");
    //NET::write_blif("../experiments/power/result_no_power/"+test_case, netlist);
    NET::write_blif("../experiments/power/result/"+test_case, netlist);
}