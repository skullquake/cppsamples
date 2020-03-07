#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
		|ranges::views::remove_if([](auto b){return b>2&&b<=8;})
	;
	for(auto b:a){
		std::cout<<b<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
