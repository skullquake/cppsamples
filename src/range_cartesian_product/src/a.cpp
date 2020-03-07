#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::vector<std::string> a={"a","b","c"};
	std::vector<std::string> b={"c","d","e"};
	std::vector<std::string> c={"f","g","h"};
	auto d=ranges::view::cartesian_product(a,b,c);
	for(auto e:d){
		std::cout
			<<"["
			<<std::get<0>(e)<<":"
			<<std::get<1>(e)<<":"
			<<std::get<2>(e)
			<<"]"
			<<std::endl
		;
	}
	return 0;
}
