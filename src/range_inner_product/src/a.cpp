#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<ranges::inner_product(
				std::vector<int>{1,2,3},
				std::vector<int>{4,5,6},
				0
		)
		<<std::endl;
	return 0;
}
