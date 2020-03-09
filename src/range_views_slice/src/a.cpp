/*
 * lazily creates a range that is a slice of some input range starting at some
 * offset and ending at some offset
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::iota(0,32)
		|ranges::views::slice(8,16)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
