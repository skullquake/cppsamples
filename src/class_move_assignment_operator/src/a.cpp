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
		A&operator=(const A&rhs){//regular assignment operator
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<"[REG]"<<":"<<mid<<":"<<idx<<std::endl;
			if(this!=&rhs)mid=rhs.mid;
			return*this;
		}
		A&operator=(A&&rhs)noexcept{//move assignment operator
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<(void*)this<<":"<<typeid(*this).name()<<":"<<__FUNCTION__<<"[MOV]"<<":"<<mid<<":"<<idx<<std::endl;
			if(this!=&rhs){
				mid=std::move(rhs.mid);
				rhs.mid=".";
			}
			return*this;
		}
		int getidx()const{return idx;}
		std::string getmid()const{return mid;}
		static void rc(){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<idx<<std::endl;}
};
int A::idx{0};
A&&f(A&&a){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":"<<(void*)&a<<std::endl;return std::move(a);}
int main(void){
	{
		A a("test0");
		A b("test1");
		b=a;
	}
	{
		A a("test0");
		A b("test1");
		b=std::move(a);
	}

}
