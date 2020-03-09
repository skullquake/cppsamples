/*
 * lazily produces an output range that is a range of ranges that slides over
 * some input range
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=ranges::views::iota(0,8);
	for(auto b:(
		a|ranges::views::sliding(2)
	)){
		std::cout<<(b|ranges::views::all)<<std::endl;
	}
	return 0;
}
