#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3,4,5,6,7};
	std::vector<int>b{0,1,0,0,0,5,6,7};
	{
		auto c=std::mismatch(a.begin(),a.end(),b.begin(),b.end());
		if(c.first==a.end()){
			std::cout<<"no mismtaches found"<<std::endl;
		}else{
			std::cout<<"first mismatch at position "<<std::distance(a.begin(),c.first)<<": ["<<*c.first<<" > "<<*c.second<<"]"<<std::endl;
		}
	}
	{
		auto c=std::mismatch(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a==b;});
		if(c.first==a.end()){
			std::cout<<"no mismtaches found"<<std::endl;
		}else{
			std::cout<<"first mismatch at position "<<std::distance(a.begin(),c.first)<<": ["<<*c.first<<" > "<<*c.second<<"]"<<std::endl;
		}
	}
	{
		auto c=std::mismatch(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
		if(c.first==a.end()){
			std::cout<<"no mismtaches found"<<std::endl;
		}else{
			std::cout<<"first mismatch at position "<<std::distance(a.begin(),c.first)<<": ["<<*c.first<<" > "<<*c.second<<"]"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
