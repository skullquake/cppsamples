#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b;
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::copy(a.cbegin(),a.cend(),std::back_inserter(b));
	std::for_each(b.begin(),b.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	b.clear();
	std::copy(a.crbegin(),a.crend(),std::back_inserter(b));
	std::for_each(b.begin(),b.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	return EXIT_SUCCESS;
}
