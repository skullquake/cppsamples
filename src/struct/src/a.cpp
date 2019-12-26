/*
 * struct lets you encapsulate one or more existing yptes into a new type
 * the variables declared of the struct type will have all the fields
 * described by the struct
 */
#include<iostream>
struct A{
	char a;
	char b;
	int c;
	float d;
};
int main(int argc,char** argv){
	A a;
	a.a='0';
	a.b='1';
	a.c=2;
	a.c=3.4;
	std::cout<<"a.a:"<<a.a<<std::endl;
	std::cout<<"a.b:"<<a.b<<std::endl;
	std::cout<<"a.c:"<<a.c<<std::endl;
	std::cout<<"a.d:"<<a.d<<std::endl;
	return 0;
}
