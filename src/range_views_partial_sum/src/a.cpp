/*
 * lazily creates a range of cumulatively accumulating elements
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::iota(1,10)
		|ranges::views::partial_sum(std::plus<>())
		|ranges::views::all
	)<<std::endl;
	return 0;
}
