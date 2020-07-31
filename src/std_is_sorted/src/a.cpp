#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	if(std::is_sorted(a.begin(),a.end())){
		std::cout<<"sorted"<<std::endl;
	}else{
		std::cout<<"unsorted"<<std::endl;
	}
	if(std::is_sorted(a.begin(),a.end(),[](const auto&a,const auto&b){return a<b;})){
		std::cout<<"sorted"<<std::endl;
	}else{
		std::cout<<"unsorted"<<std::endl;
	}
	if(std::is_sorted(a.begin(),a.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"sorted"<<std::endl;
	}else{
		std::cout<<"unsorted"<<std::endl;
	}
	return EXIT_SUCCESS;
}
