#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,2,4,6};
	std::vector<int>b{0,2,7,7};
	{
		auto c=std::partition_point(a.begin(),a.end(),[](const auto&a){return a%2==0;});
		if(c!=a.end()){
			std::cout<<"partition point: "<<std::distance(a.begin(),c)<<std::endl;
		}else{
			std::cout<<"not partitioned"<<std::endl;
		}
	}
	{
		auto c=std::partition_point(a.begin(),a.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0));
		if(c!=a.end()){
			std::cout<<"partition point: "<<std::distance(a.begin(),c)<<std::endl;
		}else{
			std::cout<<"not partitioned"<<std::endl;
		}
	}
	{
		auto c=std::partition_point(b.begin(),b.end(),[](const auto&a){return a%2==0;});
		if(c!=b.end()){
			std::cout<<"partition point: "<<std::distance(b.begin(),c)<<std::endl;
		}else{
			std::cout<<"not partitioned"<<std::endl;
		}
	}
	{
		auto c=std::partition_point(b.begin(),b.end(),std::bind(std::equal_to<int>(),std::bind(std::modulus<int>(),std::placeholders::_1,2),0));
		if(c!=b.end()){
			std::cout<<"partition point: "<<std::distance(b.begin(),c)<<std::endl;
		}else{
			std::cout<<"not partitioned"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
