/*
 * lazily creates a range that ends at the first occurance of the value
 * or at the end of the source range, whichever comes first
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::vector<int> a={0,1,2,3,-1,4,5,6,7,8,9,-1};
	std::cout
		<<(
			 a
			|ranges::views::delimit(-1)
			|ranges::views::all
		)
		<<std::endl
	;
	return 0;
}
