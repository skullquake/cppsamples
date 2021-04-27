#include<iostream>
#include<cstdlib>
class C{
	public:
		C();
		~C();
		void setm0(const int v);
		int getm0();
		int getm0()const;//const qualifier
	private:
		int m0=42;
};
C::C(){};
C::~C(){};
void C::setm0(const int v){
	m0=v;
}
int C::getm0(){
	std::cout<<"mutable getm"<<std::endl;
	return m0;
}
int C::getm0()const{//const qualifier part if sig
	std::cout<<"const getm"<<std::endl;
	return m0;
}

int main(void){
	C c0;
	c0.setm0(24);
	const C c1{c0};
	c0.getm0();//note version 
	c1.getm0();//note version
	return EXIT_SUCCESS;
}
