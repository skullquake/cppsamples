#include<iostream>
int main(void){
	{
		auto fp=[](const auto&v){return v;};
		std::cout<<typeid(fp(42)).name()<<std::endl;
	}
#ifdef false -std=c++20 ???
	{
		auto fp=[]<typename T>(const T&v)->T{return v;};
		std::cout<<typeid(fp<int>(42)).name()<<std::endl;
	}
#endif
}
