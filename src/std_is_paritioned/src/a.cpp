/*
 * returns true if all elements in range [first,last) satisfy predicate provided before all elements that done
 */
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,2,4,6};
	std::vector<int>b{0,2,7,7};
	std::vector<int>c{7,7,4,6};
	if(std::is_partitioned(a.begin(),a.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	if(std::is_partitioned(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	if(std::is_partitioned(b.begin(),b.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	if(std::is_partitioned(b.begin(),b.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	if(std::is_partitioned(c.begin(),c.end(),[](const auto&a){return a%2==0;})){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	if(std::is_partitioned(c.begin(),c.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0))){
		std::cout<<"paritioned"<<std::endl;
	}else{
		std::cout<<"not paritioned"<<std::endl;
	}
	return EXIT_SUCCESS;
}
