#include<iostream>
#include<sstream>
#include<random>
#include<vector>
#include<map>
#include<cstdlib>
int main(void){
	//produces real values distributed on defined subintervals
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::vector<double>i{0,5,10,15};
		std::vector<double>w{0,1,1,0};
		std::piecewise_linear_distribution<>pld(i.begin(),i.end(),w.begin());//constructs a distribution object from iterators over the and interval sequences [first_i,last_i) and a matching weight sequence starting at first_w
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[pld(dre)];
		for(auto&a:m)
			std::cout<<a.first<<":"<<a.second<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::piecewise_linear_distribution<>pld({0,5,10,15},[](const auto&a){return a;});
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[pld(dre)];
		for(auto&a:m)
			std::cout<<a.first<<":"<<a.second<<std::endl;
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
