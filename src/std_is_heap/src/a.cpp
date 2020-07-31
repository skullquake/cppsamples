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
	std::vector<int>a{3,2,1,0};
	if(std::is_heap(a.begin(),a.end())){
		std::cout<<"is heap"<<std::endl;
	}else{
		std::cout<<"is not heap"<<std::endl;
	}
	if(std::is_heap(a.begin(),a.end(),[](const auto&a,const auto&b){return a<b;})){
		std::cout<<"is heap"<<std::endl;
	}else{
		std::cout<<"is not heap"<<std::endl;
	}
	if(std::is_heap(a.begin(),a.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"is heap"<<std::endl;
	}else{
		std::cout<<"is not heap"<<std::endl;
	}

	return EXIT_SUCCESS;
}
