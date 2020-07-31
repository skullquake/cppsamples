#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b{0,2,1,3};
	if(std::is_permutation(a.begin(),a.end(),b.begin(),b.end())){
		std::cout<<"found"<<std::endl;
	}else{
		std::cout<<"not found"<<std::endl;
	}
	if(std::is_permutation(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a==b;})){
		std::cout<<"found"<<std::endl;
	}else{
		std::cout<<"not found"<<std::endl;
	}
	if(std::is_permutation(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"found"<<std::endl;
	}else{
		std::cout<<"not found"<<std::endl;
	}
	return EXIT_SUCCESS;
}
