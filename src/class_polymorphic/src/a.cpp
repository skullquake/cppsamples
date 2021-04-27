#include<iostream>
#include<iomanip>
#include<vector>
class Base{
	public:
		Base(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}
		virtual ~Base(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}
		virtual void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}
};
class Sub0:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub1:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub2:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub3:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub4:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub5:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub6:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub7:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
class Sub8:public Base{public:void f(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)this<<":"<<(void*)__FUNCTION__<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl;}};
int main(void){
	std::vector<Base*>v{new Sub0,new Sub1,new Sub2,new Sub3,new Sub4,new Sub5,new Sub6,new Sub7,new Sub8};
	for(const auto&e:v)e->f();
	for(const auto&el:v)delete(el);
}
