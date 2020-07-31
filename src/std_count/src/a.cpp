#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>v{0,1,1,2,2,2,3,3,3,3};
	std::for_each(v.begin(),v.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::cout<<std::count(v.begin(),v.end(),2)<<std::endl;//value
	std::cout<<std::count_if(v.begin(),v.end(),[](const auto&a){return a%2==0;})<<std::endl;//lambda
	std::cout<<std::count_if(v.begin(),v.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))<<std::endl;//operator wrapper
	std::cout<<std::count_if(v.begin(),v.end(),[](const auto&a){return a==2;})<<std::endl;//lambda
	std::cout<<std::count_if(v.begin(),v.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,2))<<std::endl;//operator wrapper
	std::cout<<std::count_if(v.begin(),v.end(),[](const auto&a){return a>=1&&a<=2;})<<std::endl;//lambda
	std::cout<<std::count_if(v.begin(),v.end(),std::bind(std::logical_and<>(),std::bind(std::greater_equal<int>(),std::placeholders::_1,1),std::bind(std::less_equal<int>(),std::placeholders::_1,2)))<<std::endl;//operator wrapper
	return EXIT_SUCCESS;
}
