#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdlib>
int main(void){
	std::vector<int>a{3,2,1,0};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		auto b=std::minmax_element(a.begin(),a.end());
		std::cout<<"[";
		if(b.first!=a.end()){
			std::cout<<(*b.first);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<",";
		if(b.second!=a.end()){
			std::cout<<(*b.second);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<"]"<<std::endl;
	}
	{
		auto b=std::minmax_element(a.begin(),a.end(),[](const auto&a,const auto&b){return a<b;});
		std::cout<<"[";
		if(b.first!=a.end()){
			std::cout<<(*b.first);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<",";
		if(b.second!=a.end()){
			std::cout<<(*b.second);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<"]"<<std::endl;
	}
	{
		auto b=std::minmax_element(a.begin(),a.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2));
		std::cout<<"[";
		if(b.first!=a.end()){
			std::cout<<(*b.first);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<",";
		if(b.second!=a.end()){
			std::cout<<(*b.second);
		}else{
			std::cout<<"NULL";
		}
		std::cout<<"]"<<std::endl;
	}
	return EXIT_SUCCESS;
}
