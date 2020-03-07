/*
 * lazily concatenates ranges
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<ranges::views::all(
			ranges::views::concat(
				 ranges::views::ints(1,ranges::unreachable)
				|ranges::views::take(8)
				|ranges::views::transform([](int b){
					return b*1;
				}),
				 ranges::views::ints(1,ranges::unreachable)
				|ranges::views::take(8)
				|ranges::views::transform([](int b){
					return b*10;
				}),
				 ranges::views::ints(1,ranges::unreachable)
				|ranges::views::take(8)
				|ranges::views::transform([](int b){
					return b*100;
				})

			)
		  )
		<<std::endl
	;
	return 0;
}
