#include<iostream>
#include<unordered_map>
int main(int argc,char** argv){
	std::unordered_map<std::string,std::string> a={
		{"k0","v0"},
		{"k1","v1"},
		{"k2","v2"},
		{"k3","v3"}
	};
	for(auto b:a){
		std::cout<<"["<<b.first<<":"<<b.second<<"]";
	}
	std::cout<<std::endl;
	return 0;
}
