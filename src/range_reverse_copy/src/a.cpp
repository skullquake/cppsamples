#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10);
	std::vector<int> b;
	ranges::reverse_copy(a,ranges::back_inserter(b));
	std::cout<<ranges::views::all(a)<<std::endl;
	std::cout<<ranges::views::all(b)<<std::endl;
	return 0;
}
