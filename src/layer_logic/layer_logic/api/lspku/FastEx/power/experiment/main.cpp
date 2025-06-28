//
 // Created by zephyr on 2023/8/1.
 //
 
 #include "../../share/power/power.h"
 #include "../../share/netlist/netlist.h"
 
 int main(int argc, char**argv) {

     exact::generate_netlist_library_power("../experiment/optimal_library_"+std::string(argv[1])+".txt", 4, 5, true,
                                           std::stoi(argv[1])*std::stoi(argv[2]), std::stoi(argv[2]));
 
 }
