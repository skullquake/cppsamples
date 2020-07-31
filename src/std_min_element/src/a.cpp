#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdlib>
int main(void){
	std::vector<int>v{0,1,2,3};
	std::for_each(v.begin(),v.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		auto a=std::min_element(v.begin(),v.end());
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),[](const auto&a,const auto&b){return a<b;});
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),[](const auto&a,const auto&b){return a>b;});
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2));
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_2,std::placeholders::_1));
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,std::placeholders::_2));
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto a=std::min_element(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_2,std::placeholders::_1));
		if(a!=v.end()){
			std::cout<<"found:"<<(*a)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
