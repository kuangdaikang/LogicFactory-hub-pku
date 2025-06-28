#include <iostream>
#include <vector>
#include <fstream>
#include "../../share/exact_synthesis/exact.h"

int main() {
    // 示例逻辑函数，这里使用简单的逻辑函数进行演示
    std::vector<exact::Boolean> functions = {
        exact::Boolean("0001")
    };

    // 创建 SSV 对象
    exact::SSV ssv(functions);
    ssv.r = 1; // 设置 r 值

    // 编码逻辑综合问题为 SAT 问题
    exact::Encoding encoding = ssv.encode(true);

    // 指定 SAT 编码输出文件的路径
    std::string sat_output_path = "../experiment/output.cnf";
    std::ofstream sat_file(sat_output_path);
    if (!sat_file.is_open()) {
        std::cerr << "Failed to open SAT output file: " << sat_output_path << std::endl;
        return 1;
    }
    encoding.write_dimacs(sat_file);
    sat_file.close();
    std::cout << "SAT encoding written to " << sat_output_path << std::endl;

    // 示例 SAT 解
    auto sat_solution = exact::synthesis(&ssv, "kissat", std::cout);

    // 指定解码后的逻辑电路输出文件的路径
    std::string circuit_output_path = "../experiment/decoded_circuit.blif";
    ssv.decode(sat_solution.second, circuit_output_path);

    std::cout << "Decoded circuit written to " << circuit_output_path << std::endl;

    return 0;
}