#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(ranges::is_sorted(
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
		)?"sorted":"not sorted")
		<<std::endl
	;
	std::cout
		<<(ranges::is_sorted(
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
		|ranges::views::reverse
		)?"sorted":"not sorted")
		<<std::endl
	;
	return 0;
}
