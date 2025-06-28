#include <iostream>
#include "netlist.h"
#include <fstream>
#include <string>
#include <time.h>
using namespace PASyn;
int main(int argc, char** argv) {
    /*
    std::set<std::string> result = npn("abcdefgh");
    for(auto& entry: result)
        std::cout<<entry<<"\n";
    */
    Technology technology{};
    Netlist netlist{};
    // std::string design(argv[1]);
    // std::cout<<design<<std::endl;
    read_liberty(argv[2], technology);
    switch_pre_process(technology);
    // /*for(auto node: netlist.nodes)
    //     std::cout<<node->load_capacitance<<" "<<node->max_depth<<"\n";
    //     */
    PASyn::read_blif(argv[1], netlist, &technology);
    // //PASyn::read_blif("/data/zousunan/PowerAwareSynthesis/benchmarks/model_Dec_Nan15/abc_mapped/"+design+".blif", netlist);
    // clock_t start,end;
    // start = clock();
    // PASyn::calculate_probability_1(netlist);
    // PASyn::calculate_power(netlist, technology);
    // end = clock();
    // std::cout<<double(end-start)*1000/CLOCKS_PER_SEC<<std::endl;
    //netlist.clear();
    //start=clock();
    //PASyn::get_feature_glitch("/Users/mac/Desktop/Lab/PowerAwareSynthesis/EPFL/int2float.blif");
    //end=clock();
    //std::cout<<double(end-start)*1000/CLOCKS_PER_SEC<<std::endl;
    std::vector<double> result = calculate_power(netlist, technology);
    //PASyn::write_verilog("/rshome/sunan.zou/nas/PowerAwareSynthesis/benchmarks/model_Dec_Nan15/abc_our_map/"+design+".vh", netlist, technology);
    // std::vector<double> features = PASyn::get_feature_glitch(argv[1]);
    std::ofstream fout(argv[3], std::ios::out);
    for(auto& entry: result) {
        fout<<entry<<" ";
    }
    fout.close();
    return 0;
}
