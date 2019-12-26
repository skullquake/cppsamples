/*
 * to avoid common memory problems you should use smart pointers instead of
 * raw pointer
 * std::unique_ptr is a smart pointer
 * unique_ptr takes ownership of the object pointed to
 * if it goes out of scope the object is deleted
 * use std::make_unique<TYPE>() to create the object pointed to
 * include the <memory> header to use it
 * you dont have to call delete, it will be managed for you
 *
 * in the example below, you can see ownership taken by the pointer
 * to type class B, and when it goes out of scope, that the destructor
 * is called, verifying that the smart pointer does what it is supposed to do
 */
#include<iostream>
#include<memory>
struct A{
	int a;
	int b;
};
class B{
	public:
		B(){
			std::cout<<"B()"<<std::endl;
		};
		~B(){
			std::cout<<"~B()"<<std::endl;
		};
	private:
	protected:
};
int main(int argc,char** argv){
	auto a=std::make_unique<A>();
	a->a=0;
	a->b=1;
	std::cout<<a->a<<std::endl;
	std::cout<<a->b<<std::endl;
	{
		auto b=std::make_unique<B>();
	}
	{
		auto b=std::make_unique<B>();
	}
	return 0;
}
