#include<iostream>
class A{
	public:
		A(){}
		~A(){}
		void f(){}
	private:
};
class B:public A{
	public:
		B(){}
		~B(){}
		void f(){A::f();}//access base class
	private:
};
int main(void){}
