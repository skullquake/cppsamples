#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<ranges::count(
			 ranges::views::ints(1,ranges::unreachable)
			|ranges::views::take(10),
			5
		)
		<<std::endl;
	return 0;
}
