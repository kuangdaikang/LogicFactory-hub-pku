#include <iostream>
#include "exact.h"
#include "../netlist/netlist.h"
#include "../utility/utility.h"

int main(int argc, char *argv[]) {
    int num_inputs;

    /*
    Test single encoding
    */
    exact::SSV ssv(std::vector<exact::Boolean> {exact::Boolean("0001")});
    ssv.r = 1;
    auto result = exact::synthesis(&ssv, "kissat", std::cout);
    ssv.decode(result.second, "./temp1.blif");
    /*
     * Profiling
     */
    /*
    std::ofstream fout(argv[2], std::ios::out|std::ios::app);
    std::ostream &out = fout;

    std::string encoding = "SSV", symmetry="";
    std::vector<std::string>encoding_list = std::vector<std::string>{"SSV", "MSV", "DITT"};
    std::vector<std::string>symmetry_list = std::vector<std::string>{"NARCS", "NARCOS", "ARCS", "NOS", "NARCO", "ARS",
                                            "NARCS", "NARCOS", "NARC", "AOS", "NARS", "NACOS",
                                            "NARCS", "NRCS", "AO", "NCOS", "NCO", "NRS",};
    
    std::ifstream fin(argv[1]);
    assert(fin.is_open() && fout.is_open());
    std::cout<<argv[1] << " " << argv[2] << "\n";
    std::string hex, temp, exp;
    while (fin >> hex) {
        out << "0x" << hex <<"\n";
        std::cout << "0x" << hex <<"\n";
        exact::Boolean func(hex);
        std::vector<exact::Boolean> funcs = {func};

        exact::DITT ditt(funcs);
        exact::SSV ssv(funcs);
        exact::MSV msv(funcs);
        for (int i = 0; i<3; i++) {
            //for (int j = i*6; j<(i+1)*6; j++) {
                encoding = encoding_list[i];
                //symmetry = symmetry_list[j];
                //out << encoding << " " << symmetry << " ";
                symmetry = "";
                out << encoding << " ";
                exact::Encoder *encoder = nullptr;
                if (encoding == "DITT") {
                    encoder = &ditt;
                } else if (encoding == "SSV") {
                    encoder = &ssv;
                } else if (encoding == "MSV") {
                    encoder = &msv;
                }

                if (symmetry.find('N') != std::string::npos)
                    encoder->non_trivial = true;
                if (symmetry.find('A') != std::string::npos)
                    encoder->all_steps = true;
                if (symmetry.find('R') != std::string::npos)
                    encoder->no_replication = true;
                if (symmetry.find('C') != std::string::npos)
                    encoder->lexicographical_step = true;
                if (symmetry.find('O') != std::string::npos)
                    encoder->lexicographical_op = true;
                if (symmetry.find('S') != std::string::npos)
                    encoder->ordered_symmetric = true;
                encoder->r = 1;
                auto result = synthesis(encoder, "kissat", out);
                // out<<(result.first ? "SAT" : "UNSAT") <<std::endl;
                out.flush();
            //}
        }   
    }

    fin.close();
    fout.close();
    return 0;
    */

    /*
    Generate Training Data
    */
   /*
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2], std::ios::out);
    assert(fin.is_open() && fout.is_open());
    std::string hex, encoding, symmetry, time, tmp;
    while(fin>>hex) {
        u_int32_t best_time = UINT32_MAX;
        std::string best_encoding, best_symmetry;
        int feature_size = D_INFLUENCE + D_COFACTOR2 + D_COFACTOR + D_BITS;
        int* feature = new int[feature_size];
        std::cout<<hex.substr(2)<<"\n";
        calculate_feature(hex.substr(2), feature);
        // for (int i=0; i<feature_size; i++) {
        //     int data = feature[i];
        //     std::cout<<data<<" ";
        // }
        // std::cout<<"\n";
        for(int i=0; i<18; i++) {
            fin>>encoding >> symmetry >> tmp>> time;
            if (best_time > std::stoi(time)) {
                best_time = std::stoi(time);
                best_encoding = encoding;
                best_symmetry = symmetry;
            }
        }
        fout<<hex<< " " << best_encoding << " " << best_symmetry << " " << best_time << " ";
        for (int i=0; i<feature_size; i++) {
            fout<<feature[i]<<" ";
        }
        fout<<"\n";
        delete [] feature;
    }
    */
}
