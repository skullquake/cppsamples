#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cstdlib>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::for_each(a.rbegin(),a.rend(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	return EXIT_SUCCESS;
}
