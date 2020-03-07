/*
 * lazily removes all elements based on the boolean return of a functor or lambda from
 * some source range
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	std::cout
		<<(
			 ranges::views::ints(1,ranges::unreachable)
			|ranges::views::take(8)
			|ranges::views::drop_while([](int a){
				return a%2==0;
			})
			|ranges::views::all
		)
		<<std::endl
	;
	return 0;
}
