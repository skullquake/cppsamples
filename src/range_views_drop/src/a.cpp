/*
 * lazily drops the first N elements from a source range
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(
			 ranges::views::ints(1,ranges::unreachable)
			|ranges::views::take(8)
			|ranges::views::drop(2)
			|ranges::views::all
		)
		<<std::endl
	;
	return 0;
}
