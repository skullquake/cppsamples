/*
 * usage:
 * specify own deleter e.g. to clean up other resources
 */
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
void deleter(const A*o){
	std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)o<<std::endl;
	if(o!=nullptr)delete o;
}
int A::idx{0};
int main(void){
	{
		auto a=std::shared_ptr<A>(new A("test0"),deleter);
	}
	{
		auto a=std::shared_ptr<A>(new A("test1"),deleter);
		a.reset();
	}
	{
		std::shared_ptr<A>(new A("test2"),deleter);
		std::shared_ptr<A>(new A("test3"),deleter);
	}

}
