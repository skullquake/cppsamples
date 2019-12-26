#include<iostream>
void a(){std::cout<<"a()"<<std::endl;}
auto b(){std::cout<<"b()"<<std::endl;}
auto c(){return 0;}//-std=c++14 return type determination
//you can get the current function's name as follows, good for logging
void d(){std::cout<<__func__<<std::endl;}
int main(int argc,char** argv){
	a();
	b();
	std::cout<<c()<<std::endl;
	d();
	return 0;
}
