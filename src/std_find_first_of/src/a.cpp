#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,3,0,1,2,3};
	std::vector<int>b{0,1,2,3};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::for_each(b.begin(),b.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		auto c=std::find_first_of(a.begin(),a.end(),b.begin(),b.end());
		if(c!=a.end()){
			std::cout<<"found:"<<(*c)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto c=std::find_first_of(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a==b;});
		if(c!=a.end()){
			std::cout<<"found:"<<(*c)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto c=std::find_first_of(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
		if(c!=a.end()){
			std::cout<<"found:"<<(*c)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
