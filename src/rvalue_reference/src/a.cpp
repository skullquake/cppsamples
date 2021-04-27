#include<iostream>
#include<memory>
#include<iomanip>
class A{
	std::string mid;
	static int idx;
	public:
		A(const std::string&pid="."):mid(pid){++idx;std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;}
		~A(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;--idx;}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
void f0(A a){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;}
void f1(A&a){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;}
A f2(A a){
	return a;
}
int main(void){
	{
		A a("test0");
		f0(a);
	}
	{
		A a("test1");
		f1(a);
	}
	{
		A a("test2");
		auto b=f2(a);
	}


}
