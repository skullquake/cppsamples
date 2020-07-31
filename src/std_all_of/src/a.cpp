#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,2,4,6};
	std::vector<int>b{0,2,4,5};
	if(std::all_of(a.begin(),a.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"all of"<<std::endl;
	}else{
		std::cout<<"not all of"<<std::endl;
	}
	if(std::all_of(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"all of"<<std::endl;
	}else{
		std::cout<<"not all of"<<std::endl;
	}
	if(std::all_of(b.begin(),b.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"all of"<<std::endl;
	}else{
		std::cout<<"not all of"<<std::endl;
	}
	if(std::all_of(b.begin(),b.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"all of"<<std::endl;
	}else{
		std::cout<<"not all of"<<std::endl;
	}
	return EXIT_SUCCESS;
}
