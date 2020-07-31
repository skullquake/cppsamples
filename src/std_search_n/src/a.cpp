/* searches a range for a number of consecutaive copies of an element */
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,2,2,3,2,2,2,1,0};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		auto b=std::search_n(a.begin(),a.end(),4,2);
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::search_n(a.begin(),a.end(),2,2);
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::search_n(a.begin(),a.end(),2,2,[](const auto&a,const auto&b){
				std::cout<<"["<<a<<","<<b<<"]"<<std::endl;	
				return a==b;});
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::search_n(a.begin(),a.end(),2,2,std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
