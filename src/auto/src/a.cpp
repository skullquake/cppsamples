#include<iostream>
#include<string>
template<typename Tl,typename Tr>
auto/*type deduction*/f(Tl l,Tr r){
	return l+r;
}
int main(void){
	{auto a{42};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{4.2};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{4.2L};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{"42"};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{std::string("42")};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{f(4,2)};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{f(4,4.2)};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{f(4,4.2L)};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{f(4.2L,2)};std::cout<<typeid(a).name()<<std::endl;}
	{auto a{f(std::string("4"),std::string("2"))};std::cout<<typeid(a).name()<<std::endl;}
}
