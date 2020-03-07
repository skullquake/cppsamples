#include<iostream>
#include<vector>
#include<algorithm>
#include<pipes/pipes.hpp>
int main(int argc,char** argv){
	{
		auto const source=std::vector<int>{0,1,2,3,4,5,6,7,8,9};
		auto destination=std::vector<int>{};
		source>>=pipes::filter([](int i){return i%2==0;})
		      >>=pipes::transform([](int i){return i*2;})
		      >>=pipes::push_back(destination);
		for(auto e:destination){
			std::cout<<e<<" ";
		}
		std::cout<<std::endl;
	}
	{
		std::vector<int> a={0,1,2,3};
		std::vector<int> b={0,10,20,30};
		std::vector<int> c;
		pipes::mux(a,b)
			>>=pipes::transform([](int a,int b){return a+b;})
			>>=pipes::push_back(c)
		;
		for(auto d:c){
			std::cout<<d<<" ";
		}
		std::cout<<std::endl;
	}
	{
		auto const a=std::vector<int>{1, 2, 3};
		auto const b=std::vector<int>{1, 2, 3};
		auto c=std::vector<int>{};
		pipes::cartesian_product(a,b)
			>>=pipes::transform([](int d, int e){
				std::cout<<"processing ["<<d<<":"<<e<<"]"<<std::endl;
				return d+e;}
			)
			>>=pipes::push_back(c)
		;
		for(auto d:c){
			std::cout<<d<<" ";
		}
		std::cout<<std::endl;
	}
	{
		auto const a=std::vector<int>{1, 2, 3};
		auto b=std::vector<int>{};
		pipes::adjacent(a)
			>>=pipes::transform([](int c,int d){
				std::cout<<"processing ["<<c<<":"<<d<<"]"<<std::endl;
				return c+d;}
			)
			>>=pipes::push_back(b)
		;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	{
		auto const a=std::vector<int>{1,2,3};
		auto b=std::vector<int>{};
		pipes::combinations(a)
			>>=pipes::transform([](int c,int d){
				std::cout<<"processing ["<<c<<":"<<d<<"]"<<std::endl;
				return c+d;}
			)
			>>=pipes::push_back(b)
		;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}
