/*
 * lazily creates a range of monotonically increasing values between
 * two specified values
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout<<(
		 ranges::views::linear_distribute(0.0,1.0,10)
		|ranges::views::all
	)<<std::endl;
	return 0;
}
