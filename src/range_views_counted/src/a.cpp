/*
 * lazily create a range that starts at the iterator begin+1 and includes the
 * next N elements
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(ranges::views::counted(
			ranges::views::ints(1,ranges::unreachable)
			.begin(),
			2
		)|ranges::views::all)
		<<std::endl
	;
	return 0;
}
