#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
int main() {
        std::ifstream fin("./optimal_library.txt");
        std::ifstream fin1("../beswac/202308/optimal_library.txt");
        //std::ofstream fout("./_optimal_library.txt");
	std::ostream& fout = std::cout;
        std::string temp;
        std::map<std::string, std::string> lower_bound;
	std::map<std::string, std::string> lower_bound1;
        while(getline(fin1, temp)) {
                if(temp[0]=='0' && (temp[1] == 'x' || temp[1] == 'X')) {
                        int num_nodes;
                        std::string _temp, function;
                        char ch;
                        std::stringstream sin(temp);
			sin>>ch>>ch>>function>>_temp;
			std::getline(sin, _temp);
                        //sin>>ch>>ch>>function>>_temp>>num_nodes;
                        //fout<<temp<<" "<<num_nodes+4<<"\n";
                        //lower_bound[function] = num_nodes;
			lower_bound1[function] = _temp;
                }
                //else fout<<temp<<"\n";
        }
	while(getline(fin, temp)) {
		if(temp[0] == '0' &&(temp[1] == 'x' || temp[1] == 'X')) {
			char ch;
			std::string _temp, function;
			std::stringstream sin(temp);
			sin>>ch>>ch>>function>>_temp;
			std::getline(sin,_temp);
			lower_bound[function] = _temp;
		}
	}
	for(auto& entry: lower_bound)
		if(lower_bound1[entry.first] != entry.second)
			//fout<<entry.first<<lower_bound1[entry.first]<<"\n";
			fout<<entry.first<<entry.second<<"\n";
        //while(getline(fin1, temp)) {
        //        std::cout<<temp;
        //        fout<<temp<<" "<<lower_bound[temp]<<"\n";
        //}
}

