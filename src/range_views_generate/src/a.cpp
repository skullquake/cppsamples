/*
 * generator
 * lazily create a range of elements to infinity
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(
			 ranges::views::generate(
				[n=1]()mutable{
					return 2*(n++);
				}
			)
			|ranges::views::take(8)
			|ranges::views::all
		)
		<<std::endl
	;
	return 0;
}
