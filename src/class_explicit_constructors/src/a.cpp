#include"./cfg/cfg.hpp"
#include<sstream>
#include<iostream>
#include<string>
class A{
		A(){};
		int m;
	public:
		A(const int&p):m(p){};
		~A(){};
};
class B{
		B(){};
		int m;
	public:
		explicit B(const int&p):m(p){};
		~B(){};
};

int main(int argc,char*argv[]){
	{A a(42);}
	{A a=42;}
	{A a(42);}
	{A a{42};}
	{B a(42);}
	//{B a=42;}
	{B a(42);}
	{B a{42};}
}
