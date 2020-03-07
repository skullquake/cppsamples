/*
 * lazily creates a range of ranges in the form of chunks
 * e.g. 4-element chunks
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	for(auto a:
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(32)
		|ranges::views::chunk(8)
	){
		std::cout<<ranges::views::all(a)<<std::endl;
	}
	return 0;
}
