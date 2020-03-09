/*
 * lazily group contiguous elements of range together based on binary predicate
 */
#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	//numeric example
	{
		auto a=
		 ranges::views::ints(1,ranges::unreachable)
		|ranges::views::transform([](int i){return 2*i+(i%2);})
		|ranges::views::take(16)
		;
		std::cout<<(ranges::views::all(a))<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
		for(auto b:
			(
			 a
			|ranges::views::group_by([](auto b,auto c){
					return b%3==c%3;
			})
		)){
			std::cout<<(ranges::views::all(b))<<std::endl;
		}
		std::cout<<"----------------------------------------"<<std::endl;
	}
	//string example
	{
		auto a=std::string("lorem ipsum sit consecutar");
		std::cout<<a<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
		ranges::sort(a);
		for(auto b:a|ranges::views::group_by([](char d,char e){
			return d==e;
		})){
			std::cout<<(ranges::views::all(b))<<std::endl;
		};
		std::cout<<"----------------------------------------"<<std::endl;
	}
	return 0;
}
