//[any_all_none_of]]
// Demonstrates any_of, all_of, none_of
// output
// vector: [6,2,3,4,5,6]
// vector any_of is_six: true
// vector all_of is_six: false
// vector none_of is_six: false
#include<range/v3/algorithm/all_of.hpp>
#include<range/v3/algorithm/any_of.hpp>
#include<range/v3/algorithm/for_each.hpp>
#include<range/v3/algorithm/none_of.hpp>
#include<range/v3/view/all.hpp>
#include<iostream>
#include<vector>
auto is_six=[](int i){return i==6;};
int main(int argc,char ** argv){
	std::vector<int> v{6,2,3,4,5,6};
	std::cout<<std::boolalpha;
	std::cout<<"vector: "<<ranges::views::all(v)<<'\n';
	std::cout<<"vector any_of is_six: "<<ranges::any_of(v,is_six)<<'\n';
	std::cout<<"vector all_of is_six: "<<ranges::all_of(v,is_six)<<'\n';
	std::cout<<"vector none_of is_six: "<<ranges::none_of(v,is_six)<<'\n';
	return 0;
}
