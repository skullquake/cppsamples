/*
 * lazily reverses some input range
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::iota(0,8)
		|ranges::views::reverse
		|ranges::views::all
	)<<std::endl;
	return 0;
}
