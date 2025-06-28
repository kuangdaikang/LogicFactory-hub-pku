#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<cassert>
int main() {
	std::ifstream fin("./optimal_library.txt");
	std::ifstream fin1("../../documents/4npn_map.txt");
	std::ofstream fout("./optimal_library_expand.txt");
	assert(fin.is_open());
	assert(fin1.is_open());
	assert(fout.is_open());
	std::string temp;
	std::map<std::string, std::vector<std::string>> npn_map;
	std::vector<std::string> functions = {};
	std::string npn_class;
	while(getline(fin1, temp)) {
		if(temp.find(':') != std::string::npos) {
			functions = {};
			npn_class = temp.substr(0, temp.find(':'));
			//std::cout<<npn_class;
		}
		else if(temp == "") {
			npn_map[npn_class] = functions;
			//std::cout<<" "<<functions.size()<<"\n";
		}
		else
			functions.emplace_back(temp);
	}

	while(getline(fin, temp)) {
		if(temp[0]=='0' && (temp[1] == 'x' || temp[1] == 'X')) {
			int num_nodes;
			char ch;
			std::string _temp, function;
			std::stringstream sin(temp);
			sin>>ch>>ch>>function;
			getline(sin, _temp);
			//fout<<temp<<num_nodes+4<<"\n";
			//fout<<temp<<"\n";
			//std::cout<<function;
			for(auto& entry: npn_map[function]) {
				fout<<"0x"<<entry<<_temp<<"\n";
			}
		}
		else fout<<temp<<"\n";
	}
}

