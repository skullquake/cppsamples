/*
 * lazily takes elements until some boolean predicate fails
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		ranges::views::iota(0,16)
		|ranges::views::take_while([](auto a){
			return a<8;
		})
		|ranges::views::all
	)<<std::endl;
	return 0;
}
