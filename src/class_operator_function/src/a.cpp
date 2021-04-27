#include<iostream>
class A{
	public:
		A(const int&p=0):m(p){}
		~A(){}
		int operator()(int p=2){return m+=p;}
	private:
		int m;
};
int main(void){
	{
		A a;
		std::cout<<a()<<std::endl;
		std::cout<<a()<<std::endl;
		std::cout<<a()<<std::endl;
	}
	{
		std::cout<<A(2)(3)<<std::endl;
	}
}
