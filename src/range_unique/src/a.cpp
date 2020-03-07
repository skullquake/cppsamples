#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::vector<int> a={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4};
	std::cout<<ranges::views::all(a)<<std::endl;
	a|=ranges::actions::sort|ranges::actions::unique;
	std::cout<<ranges::views::all(a)<<std::endl;
	return 0;
}
