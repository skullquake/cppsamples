#include<iostream>
template<typename T>
T add(T l,T r){return l+r;}
int main(void){
	std::cout<<typeid(add<int>(4,2)).name()<<std::endl;
	std::cout<<typeid(add/*type deduction*/(4,2)).name()<<std::endl;
}
