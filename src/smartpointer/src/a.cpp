#include<iostream>
#include<iomanip>
#include<memory>
#include<string>
class A{
	public:
		A(const std::string&pid="."):mid(pid){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<std::endl;}
		~A(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<std::endl;}
	private:
		std::string mid;
};
void f0(std::unique_ptr<A>p){}
void f1(std::unique_ptr<A>*p){}
int main(void){
	{
		std::unique_ptr<A>a(new A("test0"));
	}
	{
		auto a=std::make_unique<A>("test1");
	}
	{
		std::unique_ptr<A>a(new A("test2"));
		a.reset();
	}
#ifdef false
	{
		//src/a.cpp:27:10: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]’
		//   auto b=a;
		std::unique_ptr<A>a(new A("test3"));
		auto b=a;
	}
#endif
	{
		std::unique_ptr<A>a(new A("test3"));
		auto b=a.release();
		std::unique_ptr<A>c(b);
		b==nullptr;
	}
	{
		std::unique_ptr<A>a(new A("test4"));
		auto b=std::move(a);
	}
#ifdef false
	{
		//src/a.cpp:43:6: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]’
		//   f0(a);
		std::unique_ptr<A>a(new A("test5"));
		f0(a);
	}
#endif
	{
		//bad style
		std::unique_ptr<A>a(new A("test5"));
		f1(&a);
	}
}
