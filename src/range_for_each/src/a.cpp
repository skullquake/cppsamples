#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	
	ranges::for_each(
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10),
		[](int a){
			std::cout<<a<<" ";
		}
	);
	std::cout<<std::endl;
	return 0;
}
