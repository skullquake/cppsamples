/*
 * lazily tokenizes a string based on some regular expression
 */
#include<iostream>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=std::string{"lorem ipsum  sit     consecutar"};
	std::cout<<(
		a
		|ranges::views::tokenize(std::regex{"[\\w]+"})
		|ranges::views::all
	)<<std::endl;
	return 0;
}
