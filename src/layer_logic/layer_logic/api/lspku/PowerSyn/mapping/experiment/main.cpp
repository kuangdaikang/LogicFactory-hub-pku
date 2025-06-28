#include "../../share/netlist.h"

int main() {
    std::string input = "../experiment/input.blif";
    std::string technology_input = "../experiment/technology.lib";
    std::string output = "../experiment/output.v";

    PASyn::technology_mapping_api(input, technology_input, output);

    return 0;
}