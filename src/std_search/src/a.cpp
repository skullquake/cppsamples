#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		std::vector<int>b{1,2};
		auto c=std::search(a.begin(),a.end(),b.begin(),b.end());
		if(c!=a.end()){
			std::cout<<"found"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		std::vector<int>b{1,2};
		auto c=std::search(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a==b;});
		if(c!=a.end()){
			std::cout<<"found"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		std::vector<int>b{1,2};
		auto c=std::search(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
		if(c!=a.end()){
			std::cout<<"found"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
