/*
 * lazily creates an infinite range of some specified value
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::repeat(8)
		|ranges::views::take(8)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
