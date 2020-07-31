#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,2,5,7};
	std::vector<int>b{1,3,5,7};
	if(std::none_of(a.begin(),a.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"none of"<<std::endl;
	}else{
		std::cout<<"not none of"<<std::endl;
	}
	if(std::none_of(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"none of"<<std::endl;
	}else{
		std::cout<<"not none of"<<std::endl;
	}
	if(std::none_of(b.begin(),b.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"none of"<<std::endl;
	}else{
		std::cout<<"not none of"<<std::endl;
	}
	if(std::none_of(b.begin(),b.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"none of"<<std::endl;
	}else{
		std::cout<<"not none of"<<std::endl;
	}
	return EXIT_SUCCESS;
}
