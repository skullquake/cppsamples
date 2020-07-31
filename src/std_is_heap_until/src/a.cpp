/*
 * heap:
 * each element in the array represents a tree node
 * the parent/child relationship is defined implicitly by the index of the element
 */
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{3,2,1,4};
	{
		auto b=std::is_heap_until(a.begin(),a.end());
		if(b!=a.end()){
			std::cout<<"is heap until position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"is heap"<<std::endl;
		}
	}
	{
		auto b=std::is_heap_until(a.begin(),a.end(),[](const auto&a,const auto&b){return a<b;});
		if(b!=a.end()){
			std::cout<<"is heap until position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"is heap"<<std::endl;
		}
	}
	{
		auto b=std::is_heap_until(a.begin(),a.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2));
		if(b!=a.end()){
			std::cout<<"is heap until position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<"is heap"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
