#include<iostream>
#include<sstream>
#include<random>
#include<vector>
#include<map>
#include<cstdlib>
int main(void){
	//std::piecewise_constant_distribution produces random floating-point numbers, which are uniformly distributed within each of the several subintervals [bi, bi+1), each with its own weight w. i is the set of interval boundaries and the set of weights that are parameters of this distribution
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::vector<double> i{0,1,10,15};
		std::vector<double> w{1,0,1};
		std::piecewise_constant_distribution<>pcd(i.begin(),i.end(),w.begin());//constructs a distribution obect from iterators over the interval sequence [first_i,lasti) and matching weight sequence starting at first_w
		std::map<int,int>m;
		for(size_t n=0;n<1024;++n)
			++m[pcd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::piecewise_constant_distribution<>pcd({0,1,10,15},[](const auto&a){return a;});//constructs a distribution object where the intervals are taken from the initializer list bl and the wieghts generated by the function fw
		std::map<int,int>m;
		for(size_t n=0;n<1024;++n)
			++m[pcd(dre)];
		for(auto&p:m)
			std::cout<<p.first<<":"<<p.second<<std::endl;
		std::cout<<std::endl;

	}
	{
		std::random_device rd;
		std::default_random_engine dre(rd());
		std::piecewise_constant_distribution<>pcd(4,0,1,[](const auto&a){return a;});//constructs a distribution object with the nw intervals distributed uniformly over [xmin,xmas] and the weights generated by the function fw
	}
	return EXIT_SUCCESS;
}
