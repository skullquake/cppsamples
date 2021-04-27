/* *note: post increment operators are generally more expensive than pre increment operators */
#include<iostream>
class Num{
	public:
		Num(const int&p=0):m(p){};
		~Num(){};
		Num&operator++(){m+=1;return*this;};//prefix
		Num&operator--(){m+=1;return*this;};//prefix
		Num&operator++(int/*dummy*/){/*copy*/Num tmp=*this;m+=1;return tmp;};//postfix *dummy always int
		Num&operator--(int/*dummy*/){/*copy*/Num tmp=*this;m+=1;return tmp;};//postfix *dummy always int
		friend std::ostream&operator<<(std::ostream&os,const Num&rhs);
	private:
		int m;
};
std::ostream&operator<<(std::ostream&os,const Num&rhs){
	os<<rhs.m;
	return os;
}
int main(void){
	Num a;
	std::cout<<a<<std::endl;
	//prefix
	std::cout<<++a<<std::endl;
	std::cout<<--a<<std::endl;
	std::cout<<++(++a)<<std::endl;
	std::cout<<--(--a)<<std::endl;
	std::cout<<a.operator++()<<std::endl;
	std::cout<<a.operator--()<<std::endl;
	std::cout<<(a.operator++()).operator++()<<std::endl;
	std::cout<<(a.operator--()).operator--()<<std::endl;
	//postfix
	std::cout<<a++<<std::endl;
	std::cout<<a--<<std::endl;
	std::cout<<(a++)++<<std::endl;
	std::cout<<(a--)--<<std::endl;
	std::cout<<a.operator++(0/*dummy*/)<<std::endl;
	std::cout<<a.operator--(0/*dummy*/)<<std::endl;
	std::cout<<(a.operator++(0/*dummy*/)).operator++(0/*dummy*/)<<std::endl;
	std::cout<<(a.operator--(0/*dummy*/)).operator--(0/*dummy*/)<<std::endl;
}
