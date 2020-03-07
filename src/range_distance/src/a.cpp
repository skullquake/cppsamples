#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto sz=ranges::distance(
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
	);
	std::cout<<sz<<std::endl;
	return 0;
}
