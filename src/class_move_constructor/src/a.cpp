#include<iostream>
#include<iomanip>
#include<utility>
#include<vector>
class A{
	std::string mid;
	static int idx;
	public:
		A(const std::string&pid="."):mid(pid){
			++idx;
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;
		}
		A(A&&rhs)noexcept{
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<"[MOVE]"<<":"<<mid<<":"<<idx<<std::endl;
			mid=std::move(rhs.mid);
			rhs.mid=".";//reset: ensure rhs in reasonable state
		}
		~A(){
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;
			--idx;
		}
		int getidx()const{return idx;}
		std::string getmid()const{return mid;}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
A&&f(A&&a){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;return std::move(a);}
int main(void){
	{
		int a=42;
		auto b=std::move(a);
	}
	{
		//basically under the hood a cast to an rvalue reference is done
		int a=42;
		auto b=static_cast<int&&>(a);
	}
#ifdef false
	{
		A a("test0");
		A b("test1");
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&b<<std::endl;
		std::swap(a,b);
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&b<<std::endl;
	}
#endif
	{
		A a("test0");
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;
		auto b=std::move(a);
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&b<<std::endl;
	}
	{
		A a("test0");
		std::cout<<a.getmid()<<std::endl;
		auto b=f(std::move(a));
		std::cout<<a.getmid()<<std::endl;
		std::cout<<b.getmid()<<std::endl;
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;
		std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&b<<std::endl;
	}


}
