/*
 * produces lazily a range from some input range that consists of elements
 * obtained from some specified stride value
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::iota(0,8)
		|ranges::views::stride(2)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
