#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b{0,1,2,2};
	std::vector<int>c{0,1,2,4};
	if(std::lexicographical_compare(a.begin(),a.end(),b.begin(),b.end())){
		std::cout<<"a<b"<<std::endl;
	}else{
		std::cout<<"a>b"<<std::endl;
	}
	if(std::lexicographical_compare(a.begin(),a.end(),b.begin(),b.end(),[](const auto&a,const auto&b){return a<b;})){
		std::cout<<"a<b"<<std::endl;
	}else{
		std::cout<<"a>b"<<std::endl;
	}
	if(std::lexicographical_compare(a.begin(),a.end(),b.begin(),b.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"a<b"<<std::endl;
	}else{
		std::cout<<"a>b"<<std::endl;
	}
	if(std::lexicographical_compare(a.begin(),a.end(),c.begin(),c.end())){
		std::cout<<"a<c"<<std::endl;
	}else{
		std::cout<<"a>c"<<std::endl;
	}
	if(std::lexicographical_compare(a.begin(),a.end(),c.begin(),c.end(),[](const auto&a,const auto&b){return a<b;})){
		std::cout<<"a<c"<<std::endl;
	}else{
		std::cout<<"a>c"<<std::endl;
	}
	if(std::lexicographical_compare(a.begin(),a.end(),c.begin(),c.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2))){
		std::cout<<"a<c"<<std::endl;
	}else{
		std::cout<<"a>c"<<std::endl;
	}
	return EXIT_SUCCESS;
}
