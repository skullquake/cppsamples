#include<iostream>
#include<sstream>
#include<random>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
int main(void){
	//std::discrete distrubution produces random integers on the interval [0,n), where the probability of each individual integer is is defined as
	//w i/S, that is weight of the ith integer dividided by the sum of all n weights
	////std::discrete_distrubution satisfies all requirements of RandomNumberDistribution
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::discrete_distribution dd;//default constructor, constructs the distribution with a single weight p={1}. this distribution will alwys generate 0
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[dd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::discrete_distribution dd({4,3,2,1});//construct the distribution with weights in the range [first, last). if first==last, the effects are the same as of the default constructor
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[dd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::vector<int>v{1,2,3,4};
		std::discrete_distribution dd(v.begin(),v.end());//construct the distribution with weights in the range [first, last). if first==last, the effects are the same as of the default constructor
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[dd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::discrete_distribution dd(
			4,
			1,
			4,
			[](const auto&a){
				std::cout<<a<<std::endl;
				return a;
			}
		);//constructs the distribution with count weights that are generated using function unary_op. each of the weights is equal to wi=unary_op(xmin+delta/2+i*delta) with delta=(xmax-xmin)count and i {0,...,count-1). xmin and xmax must each be such that delta>0. if count==0 the effect are the same as of the default constructor
		std::cout<<std::endl;
		std::map<int,int>m;
		for(size_t i=0;i<1024;++i)
			++m[dd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
