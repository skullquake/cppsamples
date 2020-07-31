#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b;
	std::for_each(a.cbegin(),a.cend(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::copy_if(a.cbegin(),a.cend(),std::back_inserter(b),[](const auto&a){return a%2==0;});
	std::for_each(b.cbegin(),b.cend(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	b.clear();
	std::copy_if(a.crbegin(),a.crend(),std::back_inserter(b),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0));
	std::for_each(b.cbegin(),b.cend(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	return EXIT_SUCCESS;
}
