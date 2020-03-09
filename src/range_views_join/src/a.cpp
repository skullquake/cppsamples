/*
 * lazily flatten a range of ranges
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	{
		auto a=std::vector<std::vector<int>>{
			{0},
			{1,2},
			{3,4,5},
			{6,7,8,9}
		};
		for(auto b:a){
			std::cout<<(ranges::views::all(b));
		}
		std::cout<<std::endl;
		std::cout<<(
			 a
			|ranges::views::join
			|ranges::views::all
		)<<std::endl;
	}
	{
		auto a=
			 ranges::views::iota(0,10)
			|ranges::views::chunk(4)
		;
		for(auto b:a){
			std::cout<<(ranges::views::all(b));
		}
		std::cout<<std::endl;
		std::cout<<(
			 a
			|ranges::views::join
			|ranges::views::all
		)<<std::endl;
	}
	return 0;
}
