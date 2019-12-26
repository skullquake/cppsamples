/*
 * strongly typed enumerations are safe and are not interpreted as integers
 * you thus cannot compare strongly typed enumerations with types
 * that are different from that enumeration
 *
 * you can also with strongly typed enumerations set the underlying
 * type to use, e.g. unsigned long
 */
#include<iostream>
enum class A{
	a,
	b,
	c
};
enum class B:unsigned long{
	d=0,
	e=1,
	f=2
};
int main(int argc,char** argv){
	A a;
	B b;
	switch(a){
		case A::a:
			std::cout<<"A::a"<<std::endl;
			break;
		case A::b:
			std::cout<<"A::b"<<std::endl;
			break;
		case A::c:
			std::cout<<"A::c"<<std::endl;
			break;
		default:
			std::cout<<"Invalid"<<std::endl;
			break;
	};
	a=A::a;
	switch(a){
		case A::a:
			std::cout<<"A::a"<<std::endl;
			break;
		case A::b:
			std::cout<<"A::b"<<std::endl;
			break;
		case A::c:
			std::cout<<"A::c"<<std::endl;
			break;
		default:
			std::cout<<"Invalid"<<std::endl;
			break;
	};
	switch(b){
		case B::d:
			std::cout<<"B::d"<<std::endl;
			break;
		case B::e:
			std::cout<<"B::e"<<std::endl;
			break;
		case B::f:
			std::cout<<"B::f"<<std::endl;
			break;
		default:
			std::cout<<"Invalid"<<std::endl;
			break;
	};
	b=B::d;
	switch(b){
		case B::d:
			std::cout<<"B::d"<<std::endl;
			break;
		case B::e:
			std::cout<<"B::e"<<std::endl;
			break;
		case B::f:
			std::cout<<"B::f"<<std::endl;
			break;
		default:
			std::cout<<"Invalid"<<std::endl;
			break;
	};
	return 0;
}
