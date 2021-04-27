/*
 * copy and swap idiom uses a class's existing copy constructor and destructor methods to provide additional efficiency for the copy assignment operator
 */
#include<iostream>
#include<iomanip>
#include<utility>
#include<vector>
#define LOGFN() ( std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl )

std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;return std::move(a);
#define LOGCLS() ( std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<std::endl )
//#define LOGCLS() ( std::cout<<"A"<<std::endl )
class A{
	std::string mid;
	static int idx;
	public:
		A(const std::string&pid="."):mid(pid){
			++idx;
			LOGCLS();
		}
		A(A&&rhs)noexcept{//copy constructor
			LOGCLS();
			mid=std::move(rhs.mid);
			rhs.mid=".";//reset: ensure rhs in reasonable state
		}
		~A(){
			LOGCLS();
			--idx;
		}
		A&operator=(A rhs){//regular:copy and swap
			//tmp copy in par
			LOGCLS();
			swap(rhs);//swap par
			return*this;
		}
		void swap(A&rhs){
			LOGCLS();
			std::swap(mid,rhs.mid);//swap data elements
		}
		int getidx()const{return idx;}
		std::string getmid()const{return mid;}
		void debug()const{
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<__FUNCTION__<<":mid:"<<mid<<":idx:"<<idx<<std::endl;
		}
		void reset(){mid=".";}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
A&&f(A&&a){LOGFN();return std::move(a);}
int main(void){
	{
		A a("test2");
		A b("test3");
		a.debug();
		b.debug();
		a=std::move(b);
		a.debug();
		b.debug();
	}
}
