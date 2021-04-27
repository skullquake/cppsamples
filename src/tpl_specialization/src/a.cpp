/*
 * when you invoke a template with a specific type, the compiler creates a specialization
 * this happens at compile time
 * this is a copy of the function for a set of types
 * in this example, note the addresses of the function is printed, indicating differentiation
 */
#include<iostream>
#include<iomanip>
#define LOG()(std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<std::endl)
template<typename T>
void f(T){LOG();}
int main(void){
	f(42);
	f(24);
	f(4.2);
	f(2.4);
	f(4.2L);
	f(2.4L);
	f("4.2");
	f("2.4");
}
