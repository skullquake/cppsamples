/*
 * constexpr can also be templated and used in template functions
 */
#include<iostream>
#include<iomanip>
#define LOG()(std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<std::endl)
template<typename T>
constexpr T foo=T(4.2);
template<typename T>
T mkfoo(){
	return foo<T>;
}
int main(void){
	std::cout<<typeid(foo<float>).name()<<std::endl;
	std::cout<<typeid(foo<double>).name()<<std::endl;
	std::cout<<typeid(mkfoo<float>()).name()<<std::endl;
	std::cout<<typeid(mkfoo<double>()).name()<<std::endl;
}
