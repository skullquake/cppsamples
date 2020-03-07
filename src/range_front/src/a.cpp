#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=  ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10);
	std::cout<<(ranges::front(a))<<std::endl;
	return 0;
}
