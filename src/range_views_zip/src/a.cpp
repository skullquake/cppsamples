#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
int main(int argc,char** argv){
	auto a=ranges::views::ints(1,ranges::unreachable)|ranges::views::take(10);
	auto b=a|ranges::views::transform([](int c){return c*2;});
	auto c=ranges::views::zip_with([](int d,int e){return std::make_pair(d,e);},a,b);
	std::cout<<ranges::views::all(a)<<'\n';
	std::cout<<ranges::views::all(b)<<'\n';
	for(auto d:c){
		std::cout<<"["<<d.first<<":"<<d.second<<"]";
	}
	std::cout<<std::endl;
	return 0;
}
