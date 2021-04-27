#include<iostream>
#include<iomanip>
template<typename/*class*/T>
T f(T t){
	std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<std::endl;
	return t;
}
template<typename/*class*/T>
T add(T t0,T t1){
	std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<std::endl;
	return t0+t1;
}
int main(void){
	std::cout<<f(42)<<std::endl;
	std::cout<<add(4,2)<<std::endl;
	std::cout<<add(4.2,2.4)<<std::endl;
	std::cout<<add(std::string("foo"),std::string("bar"))<<std::endl;
	std::cout<<add<std::string>("foo","bar")<<std::endl;
}
