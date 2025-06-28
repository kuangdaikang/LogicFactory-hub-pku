#include "../../share/netlist.h"

int main() {
    std::string input = "../experiment/input.blif";
    std::string technology_input = "../experiment/technology.lib";
    bool gym_using = 0; // 如果需要使用 gym 模式，设置为 true
    std::vector<double> power_data = PASyn::calculate_power_api(input, technology_input, gym_using);

    // 输出结果
    std::cout << "Static Power: " << power_data[0] << " W" << std::endl;
    std::cout << "Dynamic Power: " << power_data[1] << " W" << std::endl;
    std::cout << "Internal Power: " << power_data[2] << " W" << std::endl;
    std::cout << "Wire Power: " << power_data[3] << " W" << std::endl;
    std::cout << "Total Power: " << power_data[4] << " W" << std::endl;

    return 0;
}