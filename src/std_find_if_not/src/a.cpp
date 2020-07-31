#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,3};
	{
		auto b=std::find_if_not(a.begin(),a.end(),[](const auto&a){return a==1;});
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::find_if_not(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,1));
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
