/*
 * lazily combines some input ranges into an output range based on a lambda
 * or functor
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=ranges::views::iota(0,8);
	auto b=ranges::views::iota(1,9);
	auto c=ranges::views::zip_with(
		[](auto d,auto e){
			return d*e;
		},
		a,
		b
	);
	std::cout<<(
		c|ranges::views::all
	)<<std::endl;
	return 0;
}
