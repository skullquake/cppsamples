/*
 * std::function is a class template that is a general-purpose polymorphic function wrapper
 * it can store,copy, and invoke any Callable target, functions, lambda expression, bind expressions
 * or other function objects, including pointers to member functions and pointers to data members
 *
 * the stored callable object is called the target of a std::function
 * if a std::function contains no target, it is called empty
 * invoking the target empty throws a std::bad_function_call exception
 */
#include<iostream>
#include<functional>
class C0{
	public:
		void f0(){std::cout<<"C0::f0()"<<std::endl;}
};
void f0(){
	std::cout<<"f0"<<std::endl;
}
int main(int argc,char** argv){
	std::function<void()> sf0=f0;
	std::function<void(int)> sf1=[](int a){
		std::cout<<a<<std::endl;
	};
	C0 c0;
	//std::function<void()> sf2=std::bind(&C0::f0);???
	sf0();
	sf1(0);
	return 0;
}
