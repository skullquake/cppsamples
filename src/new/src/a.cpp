#include<iostream>
#include<iomanip>
class A{
	public:
		A(){
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<this<<":"<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":start"<<std::endl;
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<this<<":"<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":end"<<std::endl;
		}
		~A(){
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<this<<":"<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":start"<<std::endl;
			std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<this<<":"<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":end"<<std::endl;
		}
	private:
};
int main(void){
	std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":start"<<std::endl;
	try{
		auto a=new int;
		delete a;
	}catch(const std::bad_alloc&e){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<__FUNCTION__<<":error:"<<e.what()<<std::endl;}
	try{
		auto a=new int[2];
		delete a;
	}catch(const std::bad_alloc&e){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<__FUNCTION__<<":error:"<<e.what()<<std::endl;}
	try{
		auto a=new A();
		delete a;
	}catch(const std::bad_alloc&e){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<__FUNCTION__<<":error:"<<e.what()<<std::endl;}
	try{
		auto a=new A[2];
		delete[]a;
	}catch(const std::bad_alloc&e){std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<__FUNCTION__<<":error:"<<e.what()<<std::endl;}
	//nothrow
	{
		auto a=new(std::nothrow)int;
		if(a!=nullptr)delete a;
	}
	{
		auto a=new(std::nothrow)int[2];
		if(a!=nullptr)delete a;
	}
	{
		auto a=new(std::nothrow)A();
		if(a!=nullptr)delete a;
	}
	{
		auto a=new(std::nothrow)A[2];
		if(a!=nullptr)delete[]a;
	}
	std::cerr<<"0x"<<std::hex<<std::noshowbase<<std::setw(16)<<std::setfill('0')<<(void*)__FUNCTION__<<":"<<__FUNCTION__<<":end"<<std::endl;
}
