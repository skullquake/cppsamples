#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,2,3};
	{
		auto b=std::adjacent_find(a.begin(),a.end());
		if(b!=a.end()){
			std::cout<<"found adjacency at position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::adjacent_find(a.begin(),a.end(),[](const auto&a,const auto&b){return a==b;});
		if(b!=a.end()){
			std::cout<<"found adjacency at position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::adjacent_find(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
		if(b!=a.end()){
			std::cout<<"found adjacency at position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
