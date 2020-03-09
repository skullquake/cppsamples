/*
 * lazily produces a range from some input range that consists of all the elements
 * after the very first element
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::iota(0,8)
		|ranges::views::tail
		|ranges::views::all
	)<<std::endl;
	return 0;
}
