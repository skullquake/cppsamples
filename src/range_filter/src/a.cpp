#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
		|ranges::views::filter([](int b){
			return b%2==0;
		 })
	;
	std::cout<<ranges::views::all(a)<<std::endl;
	return 0;
}
