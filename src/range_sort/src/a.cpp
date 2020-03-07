#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::vector<int> a={1,4,2,3};
	std::cout<<ranges::views::all(a)<<std::endl;
	a|=ranges::actions::sort;
	std::cout<<ranges::views::all(a)<<std::endl;
	return 0;
}
