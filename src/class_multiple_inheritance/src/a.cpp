#include<iostream>
class A{
	public:
		A(){}
		~A(){}
};
class B{
	public:
		B(){}
		~B(){}
};
class C:public A,public B{
	public:
		C():A(),B(){}
		~C(){}
};
int main(void){
	A();
	B();
	C();
}
