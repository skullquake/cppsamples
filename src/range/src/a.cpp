#include<iostream>
//#include<range/v3/range.hpp>
#include<range/v3/all.hpp>
#include<vector>
void test0(){
	std::vector<int> numbers={1,2,3,4,5,6};
	auto results=numbers
		|ranges::views::filter([](int n){return n%2==0;})
		|ranges::views::transform([](int n){return n*2;})
	;
	for(auto result:results){
		std::cout<<result<<" ";
	}
	std::cout<<std::endl;
}
void test1(){
	std::vector<int> a={0,1,2,3};
	std::vector<int>::iterator b=ranges::find(a,1);
	if(b!=a.end()){
		std::cout<<"found:["<<(b-a.begin())<<"]"<<std::endl;
	}else{
		std::cout<<"not found"<<std::endl;
	}
}
int main(int argc,char** argv){
	test0();
	test1();
	return 0;
}
