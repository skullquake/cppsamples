#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b;
	std::for_each(a.begin(),a.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::copy_n(a.begin(),a.size()/2,std::back_inserter(b));
	std::for_each(b.begin(),b.end(),[](const auto&a){std::cout<<a<<" ";});std::cout<<std::endl;
	return EXIT_SUCCESS;
}
