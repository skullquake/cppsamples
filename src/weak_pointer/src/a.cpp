/* usage
 *
 * keeping alive:
 *
 * manager
 *       /\
 * |     |
 * wp    wp
 * |     |
 * \/
 * employee
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
		void f()const{std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<":"<<mid<<":"<<idx<<std::endl;}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
void f(const std::weak_ptr<A>&wp){
	std::cout<<wp.use_count()<<std::endl;
	auto sp=wp.lock();
	sp->f();
}
int main(void){
	{
		auto a=std::make_shared<A>("test0");
		f(a);
		a->f();
	}

}
