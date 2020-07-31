#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iterator>
#include<vector>
#include<iostream>
int main(void){
	{
		std::vector<int>a{0,1,2,3};
		std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
		std::replace_if(a.begin(),a.end(),[](const auto&a){return a%2==0;},42);
		std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	}
	{
		std::vector<int>a{0,1,2,3};
		std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
		std::replace_if(a.begin(),a.end(),std::bind(std::equal_to<int>(),(std::bind(std::modulus<int>(),std::placeholders::_1,2)),0),42);
		std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
