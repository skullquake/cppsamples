/*
 * lazily creates a range that is the difference between two input ranges
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=ranges::views::iota(0,8)|ranges::to<std::vector<int>>();
	auto b=ranges::views::iota(0,4)|ranges::to<std::vector<int>>();
	std::cout<<(ranges::views::all(a))<<std::endl;
	std::cout<<(ranges::views::all(b))<<std::endl;
	std::cout<<(
		 ranges::views::set_difference(a,b)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
