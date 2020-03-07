#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::take(10);
	std::vector<int> b;
	std::vector<int> c;
	ranges::partition_copy(
		a,
		ranges::back_inserter(b),
		ranges::back_inserter(c),
		[](int d){return d%2==0;}
	);
	std::cout<<ranges::views::all(a)<<std::endl;
	std::cout<<ranges::views::all(b)<<std::endl;
	std::cout<<ranges::views::all(c)<<std::endl;
	return 0;
}
