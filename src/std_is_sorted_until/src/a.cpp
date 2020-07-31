#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b{0,1,3,2};
	{
		auto c=std::is_sorted_until(a.begin(),a.end());
		if(c!=a.end()){
			std::cout<<"sorted until position "<<std::distance(a.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	{
		auto c=std::is_sorted_until(a.begin(),a.end(),[](const auto&a,const auto&b){return a<b;});
		if(c!=a.end()){
			std::cout<<"sorted until position "<<std::distance(a.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	{
		auto c=std::is_sorted_until(a.begin(),a.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2));
		if(c!=a.end()){
			std::cout<<"sorted until position "<<std::distance(a.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	{
		auto c=std::is_sorted_until(b.begin(),b.end());
		if(c!=b.end()){
			std::cout<<"sorted until position "<<std::distance(b.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	{
		auto c=std::is_sorted_until(b.begin(),b.end(),[](const auto&a,const auto&b){return a<b;});
		if(c!=b.end()){
			std::cout<<"sorted until position "<<std::distance(b.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	{
		auto c=std::is_sorted_until(b.begin(),b.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2));
		if(c!=b.end()){
			std::cout<<"sorted until position "<<std::distance(b.begin(),c)<<std::endl;
		}else{
			std::cout<<"sorted"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
