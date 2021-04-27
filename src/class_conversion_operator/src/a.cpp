#include<iostream>
#include<string>
class A{
	public:
		A(){};
		~A(){};
		A operator+=(const A&rhs){return*this;};
		operator std::string()const{return".";};
	private:
};
int main(void){
	std::cout<<(std::string(A()))<<std::endl;
	auto a=std::string(".");
	a+=A();
}
