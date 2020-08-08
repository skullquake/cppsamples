#include<iostream>
#include<thread>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<unistd.h>
void f(int);
class C{
	public:
		void operator()(int a);
};
int main(void){
	std::srand(time(0));
	std::vector<std::thread>vt;
	//function
	vt.push_back(std::thread(f,24));
	//function object
	vt.push_back(std::thread(C(),24));
	//lambda
	vt.push_back(std::thread([](int a){
		usleep((rand()%1000)*1000);
		std::cout<<"lambda:       "<<a<<'\n';
	},24));
	for(auto&a:vt){
		a.join();
	}
	return EXIT_SUCCESS;
}
void f(int a){
	usleep((rand()%1000)*1000);
	std::cout<<"function:     "<<a<<'\n';
}
void C::operator()(int a){
	usleep((rand()%1000)*1000);
	std::cout<<"C::operator():"<<a<<'\n';
}
