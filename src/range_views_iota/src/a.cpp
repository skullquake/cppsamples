/*
 * lazily create monotonically increating range of elements
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(
			 ranges::views::iota(0)
			|ranges::views::take(8)
			|ranges::views::all
		)
		<<std::endl
	;
	std::cout
		<<(
			 ranges::views::iota(0,8)
			|ranges::views::all
		)
		<<std::endl
	;
	std::cout
		<<(
			 ranges::views::iota('a')
			|ranges::views::take(8)
			|ranges::views::all
		)
		<<std::endl
	;
	std::cout
		<<(
			 ranges::views::iota('a','i')
			|ranges::views::all
		)
		<<std::endl
	;
	return 0;
}
