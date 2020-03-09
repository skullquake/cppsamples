/*
 * lazily retrieves values of a std::map
 */
#include<iostream>
#include<map>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=std::map<std::string,std::string>{
		{"k0","v0"},
		{"k1","v1"},
		{"k2","v2"},
		{"k3","v3"}
	};
	std::cout<<(
		 a
		|ranges::views::values
		|ranges::views::all
	)<<std::endl;
	return 0;
}
