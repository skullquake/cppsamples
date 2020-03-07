#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto eq=ranges::equal(
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10),
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
	);
	std::cout<<(eq?"equal":"not equal")<<std::endl;
	return 0;
}
