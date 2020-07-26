#include<iostream>
#include<thread>
#include<cstdlib>
#include<vector>
void f(int);
class C{
	public:
		void operator()(int a){
			std::cout<<"C::operator():"<<a<<std::endl;
		};
};
int main(void){
	std::thread t0(f,42);
	std::thread t1([](int a){
		std::cout<<a<<std::endl;
	},24);
	std::vector<std::thread>vt;
	C c;
	vt.push_back(std::thread(c,24));
	vt.push_back(std::thread([](int a){
		std::cout<<a<<std::endl;
	},24));
	int data=33;
	vt.push_back(std::thread([&](int a){
		std::cout<<data<<std::endl;
	},24));
	for(auto&a:vt){
		a.join();
	}
	t0.join();
	t1.join();
	return EXIT_SUCCESS;
}
void f(int a){
	std::cout<<a<<std::endl;
}
