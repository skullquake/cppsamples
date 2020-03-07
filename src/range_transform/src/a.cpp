#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10)
		|ranges::views::transform([](int b){
			return b*2;
		 })
	;
	std::cout<<ranges::views::all(a)<<std::endl;
	return 0;
}
