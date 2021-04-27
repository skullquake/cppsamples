#include<iostream>
class A{
	public:
		A(const int&p=0):m(42){};
		~A(){};
		A operator=(const A&rhs){m=rhs.m;return*this;};
		A operator+(const A&rhs)const{return A(m+rhs.m);};
		A operator-(const A&rhs)const{return A(m-rhs.m);};
		A operator*(const A&rhs)const{return A(m*rhs.m);};
		A operator/(const A&rhs)const{return A(m/rhs.m);};
		A&operator+=(const A&rhs){m+=rhs.m;return*this;};
		A&operator-=(const A&rhs){m-=rhs.m;return*this;};
		A&operator*=(const A&rhs){m*=rhs.m;return*this;};
		A&operator/=(const A&rhs){m/=rhs.m;return*this;};
		friend std::ostream&operator<<(std::ostream&os,const A&a);
		friend A operator+(const A&lhs,const A&rhs);
		friend A operator-(const A&lhs,const A&rhs);
		friend A operator*(const A&lhs,const A&rhs);
		friend A operator/(const A&lhs,const A&rhs);
	private:
		int m;
};
A operator+(const A&lhs,const A&rhs){return A(lhs.m+rhs.m);}
A operator-(const A&lhs,const A&rhs){return A(lhs.m-rhs.m);}
A operator*(const A&lhs,const A&rhs){return A(lhs.m*rhs.m);}
A operator/(const A&lhs,const A&rhs){return A(lhs.m/rhs.m);}
std::ostream&operator<<(std::ostream&os,const A&a){
	os<<a.m;
	return os;
};
int main(int argc,char*argv[]){
	{A a;A b;a=b;}
	{A a;A b;a+b;}
	{A a;A b;a-b;}
	{A a;A b;a*b;}
	{A a;A b;a/b;}
	{A a;std::cout<<a<<std::endl;}
}
