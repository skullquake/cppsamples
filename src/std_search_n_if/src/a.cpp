/* no such thing exists, just fake a unary predicate with a lambda/functor/function/functional */
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,2,2,3,2,2,2,1,0};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		auto b=std::search_n(a.begin(),a.end(),2,0/*dummy*/,[](const auto&a,const auto&b){
				int b_=2;/*replace*/
				std::cout<<"["<<a<<","<<b_<<"]"<<std::endl;	
				return a==b_;});
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		auto b=std::search_n(a.begin(),a.end(),2,0/*dummy*/,std::bind(std::equal_to<int>(),std::placeholders::_1,2));
		if(b!=a.end()){
			std::cout<<"found:"<<(*b)<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
