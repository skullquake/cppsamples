#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::vector<int> a={0,2,3,4,5};
	auto b=ranges::copy(a);
	std::cout<<ranges::views::all(a)<<std::endl;
	std::cout<<ranges::views::all(b)<<std::endl;
	return 0;
}
