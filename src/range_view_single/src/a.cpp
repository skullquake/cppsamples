/*
 * lazily creates a range from a single value
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::single(8)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
