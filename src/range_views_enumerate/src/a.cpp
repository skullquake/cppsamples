/*
 * lazily pairs element of the source range with an index
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=std::vector<std::string> {"foo","bar","baz"};
	for(auto b:a|ranges::views::enumerate){
		std::cout<<"["<<b.first<<":"<<b.second<<"]";
	}
	std::cout<<std::endl;
	return 0;
}
