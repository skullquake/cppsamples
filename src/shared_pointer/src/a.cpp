#include<iostream>
#include<memory>
#include<iomanip>
class A{
	std::string mid;
	static int idx;
	public:
		A(const std::string&pid="."):mid(pid){++idx;std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;}
		~A(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;--idx;}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
void f(std::shared_ptr<A>p){}
int main(void){
	{
		std::shared_ptr<A>(new A("test0"));A::rc();
	}
	{
		std::shared_ptr<A>(new A("test1"));A::rc();
		std::shared_ptr<A>(new A("test2"));A::rc();
	}
	{
		std::make_shared<A>("test3");A::rc();
	}
	{
		std::make_shared<A>("test4");A::rc();
		std::make_shared<A>("test5");A::rc();
	}
	{
		auto a=std::make_shared<A>("test6");A::rc();
		a.reset();a->A::rc();
	}
	{
		auto a=std::make_shared<A>("test7");A::rc();
		f(a);a->A::rc();
	}
	{
		auto a=std::make_shared<A>("test8");A::rc();
		auto b=std::make_shared<A>("test9");A::rc();
		f(a);a->A::rc();
		f(b);a->A::rc();
	}
	{
		auto a=std::make_shared<A>("test8");A::rc();
		auto b0=a;A::rc();
		auto b1=a;A::rc();
		auto b2=a;A::rc();
		auto b3=a;A::rc();
	}
	{
		//no release
	}
}
