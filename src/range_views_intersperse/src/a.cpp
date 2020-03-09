/*
 * lazily insert element between every element in range
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	{
		std::cout
			<<(
				 ranges::views::ints(1,ranges::unreachable)
				|ranges::views::take(8)
				|ranges::views::intersperse(0)
				|ranges::views::all
			)
			<<std::endl
		;
	}
	{
		auto a=std::string{"0123456789abcdef"};
		auto b=a
			|ranges::views::intersperse(',')
			|ranges::to<std::string>();
		std::cout
			<<b
			<<std::endl
		;
	}
	return 0;
}
