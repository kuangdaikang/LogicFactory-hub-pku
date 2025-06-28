//
 // Created by zephyr on 2023/8/1.
 //
 
 #include "power.h"
 #include "../netlist/netlist.h"
 
 int main(int argc, char**argv) {
 
     /*
      * Test Correctness of Encoding Ways
      */
 
     /*
     std::string line= "0001";
     exact::Technology technology;
     exact::Boolean func(line);
     int r=3;
     std::vector<exact::Boolean> funcs = {func};
     exact::SSV_Power encoder(funcs);
     exact::SSV encode_basic(funcs);
 
     encoder.r = r;
     encoder.target_switching_probability = 0.5;
     encode_basic.r = r;
     exact::Encoding encoding = encoder.encode(true, std::vector<double>{}, true);
     std::ofstream fout("./0001.txt");
     encoding.write_smt2(fout, true);
     exact::Encoding encoding_basic = encode_basic.encode(true);
     //encoding_basic.write_dimacs(fout);
     */
 
     /*
      * Test Power Optimal Library Generation
      */
     exact::generate_netlist_library_power("../experiments/power/20240223/optimal_library_"+std::string(argv[1])+".txt", 4, 5, true,
                                           std::stoi(argv[1])*std::stoi(argv[2]), std::stoi(argv[2]));
 
     /*
      * Test PPA pareto optical frontier of generated circuits
      */
     /*
     std::ifstream fin("../experiments/power/sub_circuit_power.txt");
     std::string temp;
     int num_inputs = 4;
     while(getline(fin,temp)) {
         int num_nodes, output_node_index;
         std::string truth_table, label;
         char temp_ch;
         std::stringstream sin(temp);
         sin >>truth_table >> num_nodes;
         Netlist *netlist = new Netlist;
         netlist->name = "o_n_" + truth_table + label;
         std::cout<<truth_table<<"\n";
         // Add primary inputs
         for (int i = 1; i <= num_inputs; i++) {
             std::string node_name = "n_" + std::to_string(i);
             Node *node = new Node(node_name);
             node->outputs.emplace_back(std::vector<std::string>());
             node->num_fanout.emplace_back(0);
             node->min_depth = 1;
             node->max_depth = 1;
             node->functions = std::vector<Function>(1, Function());
             netlist->add_node(node);
             netlist->inputs.emplace_back(node);
         }
 
         for (int i = 0; i < num_nodes; i++) {
             std::string node_name = "n_" + std::to_string(i + num_inputs + 1);
             // Add inputs
             int input_index_1, input_index_2, function_type;
             sin >> input_index_1 >> input_index_2 >> function_type;
             auto input_1 = netlist->has_node("n_" + std::to_string(input_index_1));
             if (input_1 != nullptr) {
                 (input_1->num_fanout[0])++;
                 input_1->outputs[0].emplace_back(node_name);
             } else {
                 Node *node = new Node("n_" + std::to_string(input_index_1));
                 node->outputs.emplace_back(std::vector<std::string>(1, node_name));
                 node->num_fanout.emplace_back(1);
                 netlist->add_node(node);
             }
             auto input_2 = netlist->has_node("n_" + std::to_string(input_index_2));
             if (input_2 != nullptr) {
                 (input_2->num_fanout[0])++;
                 input_2->outputs[0].emplace_back(node_name);
             } else {
                 Node *node = new Node("n_" + std::to_string(input_index_2));
                 node->outputs.emplace_back(std::vector<std::string>(1, node_name));
                 node->num_fanout.emplace_back(1);
                 netlist->add_node(node);
             }
             //Add current node
             auto node = netlist->has_node(node_name);
             if (node != nullptr) {
                 node->num_fanin = num_inputs;
                 node->inputs = std::vector<std::string>{"n_" + std::to_string(input_index_1),
                                                         "n_" + std::to_string(input_index_2)};
                 node->functions = std::vector<Function>(1, Function(function_type));
             } else {
                 node = new Node(node_name, num_inputs, std::vector<unsigned int>(1, 0),
                                 std::vector<std::string>{"n_" + std::to_string(input_index_1),
                                                          "n_" + std::to_string(input_index_2)},
                                 std::vector<Function>(1, Function(function_type)), std::vector<double>{-1});
                 netlist->add_node(node);
             }
             netlist->edges.emplace_back(new Edge(netlist->has_node("n_" + std::to_string(input_index_1)), node));
             netlist->edges.emplace_back(new Edge(netlist->has_node("n_" + std::to_string(input_index_2)), node));
         }
 
         sin >> output_node_index;
         // Add primary outputs
         netlist->outputs.emplace_back(netlist->has_node("n_" + std::to_string(output_node_index)));
         write_blif("../experiments/power/sub_circuits/power_"+truth_table+".blif", *netlist);
     }
     */
 
     /*
      * Retrace the variable assignment of partial solved SMT encoding
      */
     /*
     exact::Boolean func((std::string(argv[1])));
     std::vector<exact::Boolean> funcs = {func};
 
     exact::SSV_Power *encoder = new exact::SSV_Power(funcs);
     encoder->r = std::stoi(argv[2]);
     auto& fout = std::cout;
     std::vector<double> input_probability = {0.5, 0.5, 0.5, 0.5};
     int num_classes = 10;
     std::string encoding_method = "SSV";
     std::pair<bool, std::vector<int>> result = {true, {}};
     int temp;
     while(std::cin>>temp) {
         result.second.emplace_back(temp);
     }
 
     int r = encoder->r, max_t =
             (1 << (func.num_bits)) - 1, m = (int) funcs.size(), n = func.num_bits;
     std::map<std::string, int> variable_index = encoder->generate_variable_index(n, r, max_t, m);
     std::map<int, bool> variable_assignment;
     for (auto &entry: result.second) {
         int index = abs(entry);
         variable_assignment[index] = index == entry;
     }
     std::string label = std::to_string(int(input_probability[0]/(1.0/num_classes)));
     for(int i=1; i<input_probability.size(); i++)
         label += "+"+std::to_string(int(input_probability[i]/(1.0/num_classes)));
     fout <<label <<" " << encoder->r << " ";
     if(encoding_method == "SSV") {
         for (unsigned int i = encoder->initial_i; i < encoder->initial_i + r; i++) {
             for (int k = 1; k < i; k++) {
                 for (int j = 1; j < k; j++) {
                     if (variable_assignment[variable_index["s" + std::to_string(i) + std::to_string(j) +
                                                            std::to_string(k)]]) {
                         fout << j << " " << k << " ";
                         bool f01 = variable_assignment[variable_index["f" + std::to_string(i) + "01"]],
                                 f10 = variable_assignment[variable_index["f" + std::to_string(i) + "10"]],
                                 f11 = variable_assignment[variable_index["f" + std::to_string(i) + "11"]];
                         int function_one_hot = (f11 << 2) | (f10 << 1) | f01, function_type;
                         switch (function_one_hot) {
                             case 0:
                                 assert(false);
                             case 1:
                             case 2:
                                 function_type = 7;
                                 break;
                             case 3:
                                 function_type = 14;
                                 break;
                             case 4:
                                 function_type = 9;
                                 break;
                             case 5:
                                 function_type = 13;
                                 break;
                             case 6:
                                 function_type = 12;
                                 break;
                             case 7:
                                 function_type = 4;
                                 break;
                             default:
                                 assert(false);
                         }
                         fout << function_type << " ";
                     }
                 }
             }
         }
         fout << r << "\n";
         //fout.close();
         delete encoder;
     }
      */
 }
