//
// Created by zephyr on 7/1/2023.
//
#include "incremental.h"
#include <cstring>

int main(int argc, char** argv) {
    /*
     * Test for incremental synthesis Method2
     */
    /*
    std::string line = "01";
    exact::Technology technology;
    exact::Boolean func(line);
    int r=2;
    std::vector<exact::Boolean> funcs = {func};
    exact::SSV_Incremental encoder(funcs, 2, 3);
    encoder.r = r;
    char manual_similar[50] = "02";
    std::pair<std::vector<std::string>, std::vector<std::string>> del_add =
            encoder.incremental_encode("manual", manual_similar);
    for(auto& clause: del_add.first)
        std::cout<<clause<<"\n";
    for(auto& clause: del_add.second)
        std::cout<<"\n"<<clause;
    */

    /*
     * Test for incremental synthesis Method1
     */

    /*
    std::string line = "0000000000000001";
    exact::Technology technology;
    exact::Boolean func(line);
    int r=1;
    std::vector<exact::Boolean> funcs = {func};
    exact::SSV_Incremental encoder(funcs);
    encoder.sub_n = 5;
    encoder.r = r;
    char express[50] = "01101&&&ABC&D&EF";
    std::pair<exact::Encoding, std::vector<int>> result =
            encoder.incremental_encode("mute", express, true);
    std::ofstream fout("/rshome/sunan.zou/increment_0000000000000001.cnf", std::ios::out);
    result.first.write_dimacs(fout);
    */
    /*
     * Test DSD function generation
     */

    //exact::generate_full_dsd("../documents/dsd/full_dsd_12.txt", 12, 2000);
    //exact::generate_partial_dsd("../documents/dsd/partial_dsd_8_3.txt", 8, 3, 2000);

    /*
     *  Incremental synthesis profiling
     */

    std::string encoding, symmetry;
    assert(argc >= 2);
    std::string data_set;
    if(std::string(argv[1]) == "-p")
        data_set = "partial";
    else if(std::string(argv[1]) == "-f")
        data_set = "full";
    int num_inputs = std::stoi(argv[2]);

    std::ifstream fin("../documents/dsd/" + data_set + "_dsd_" + std::to_string(num_inputs) + ".txt");
    assert(fin.is_open());
    std::string exp, hex, temp;
    int count = 0;
    //int start = std::stoi(argv[5]);
    while (fin>>hex>>temp>>exp>>temp && count < 2000) {
    //hex = "00000000000021a2", exp = "!++!A!B[", temp = "1101111001011101";
        std::ofstream fout("../experiments/incremental/" + data_set + "/result_ours_" + std::to_string(num_inputs) + ".txt",std::ios::app | std::ios::out);
        count++;
        //if (num_inputs > 4 && ((count % 50 != 0) || (count < 50 * start)))
        //    continue;
        //fout << line << " ";
        std::cout << "0x" << hex << "\n";
        exact::Boolean func(hex);
        std::vector<exact::Boolean> funcs = {func};

        exact::SSV_Incremental ssv(funcs);
        //char similar_option[100] = "01001";   //for mute
        char similar_option[100] = "010";     //for mute_last
        strcat(similar_option, exp.c_str());
        if(data_set == "partial") {
            ssv.set_similar_function("mute_last", similar_option, 2, temp);
        } else if (data_set == "full") {
            ssv.set_similar_function("mute_last", similar_option);
        }
        std::cout<<ssv.get_similar_function()<<"\n";
        exact::SSV_Incremental *encoder = &ssv;

        encoder->r = num_inputs - 1;
        auto result = incremental_synthesis(encoder, "crypto", fout);
        if(result.first)
            count ++;
        fout.close();
    }
    fin.close();

}