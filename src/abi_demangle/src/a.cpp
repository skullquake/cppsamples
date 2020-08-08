#include<iostream>
#include<cstdlib>
#include<cxxabi.h>
#include<vector>
class C{
	public:
		C(){};
		~C(){};
		void f0(){};
		int  f1(){};
		int  f2(int){};
};
int main(void){
	{
		int i;
		int s;
		std::cout<<abi::__cxa_demangle(typeid(i).name(),nullptr,0,&s)<<std::endl;
	}
	{
		std::vector<int>v;
		int s;
		std::cout<<abi::__cxa_demangle(typeid(v).name(),nullptr,0,&s)<<std::endl;
	}
	{
		std::vector<std::vector<int>>v;
		int s;
		std::cout<<abi::__cxa_demangle(typeid(v).name(),nullptr,0,&s)<<std::endl;
	}
	{
		int s;
		std::cout<<abi::__cxa_demangle(typeid(&C::f0).name(),nullptr,0,&s)<<std::endl;
		std::cout<<abi::__cxa_demangle(typeid(&C::f1).name(),nullptr,0,&s)<<std::endl;
		std::cout<<abi::__cxa_demangle(typeid(&C::f2).name(),nullptr,0,&s)<<std::endl;
	}
	return EXIT_SUCCESS;
}
