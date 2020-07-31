#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,3};
	{
		int limit=1;
		auto b=std::find_if(a.begin(),a.end(),std::bind(std::greater<int>(),std::placeholders::_1,limit));
		if(b!=a.end()){
			std::cout<<"found"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		int limit=42;
		auto b=std::find_if(a.begin(),a.end(),std::bind(std::greater<int>(),std::placeholders::_1,limit));
		if(b!=a.end()){
			std::cout<<"found"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}

	return EXIT_SUCCESS;
}
