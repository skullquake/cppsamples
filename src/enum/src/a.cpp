#include<iostream>
enum A{a,b,c,d};
enum B{e=0,f=1,g=2,h=3};
int main(int argc,char** argv){
	A a;
	std::cout<<a<<std::endl;
	a=A::a;
	std::cout<<a<<std::endl;
	B b;
	std::cout<<b<<std::endl;
	b=B::e;
	switch(b){
		case B::e:
			std::cout<<"B::e"<<std::endl;
			break;
		case B::f:
			std::cout<<"B::f"<<std::endl;
			break;
		case B::g:
			std::cout<<"B::g"<<std::endl;
			break;
		case B::h:
			std::cout<<"B::h"<<std::endl;
			break;
		default:
			std::cout<<"Invalid"<<std::endl;
			break;
	}
	return 0;
}
