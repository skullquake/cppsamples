#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b{0,1,2,3};
	if(std::equal(a.begin(),a.end(),b.begin(),b.end())){
		std::cout<<"equal"<<std::endl;
	}else{
		std::cout<<"not equal"<<std::endl;
	}
	if(std::equal(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a==b;})){
		std::cout<<"equal"<<std::endl;
	}else{
		std::cout<<"not equal"<<std::endl;
	}
	if(std::equal(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"equal"<<std::endl;
	}else{
		std::cout<<"not equal"<<std::endl;
	}
	return EXIT_SUCCESS;
}
