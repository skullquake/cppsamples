#include<iostream>
#include<future>
#include<cstdlib>
int main(void){
	try{
		auto tsk0=[]()->int{
			std::cout<<"info:tsk0:beg"<<std::endl;
			std::cout<<"info:tsk0:end"<<std::endl;
			return 42;
		};
		auto tsk1=[](const std::shared_future<int>&sf){
			std::cout<<"info:tsk1:beg"<<std::endl;
			try{
				std::cout<<"info:tsk1:"<<sf.get()<<std::endl;
			}catch(const std::exception&e){
				std::cerr<<"error:tsk1:"<<e.what()<<std::endl;
			}
			std::cout<<"info:tsk1:end"<<std::endl;
		};
		std::shared_future<int>sf(std::async(tsk0));
		//auto sf=std::future<int>(std::async(tsk0)).share();//std::future member share transfers the shared state from *this to a std::shared_future and returns it
		std::future<void>f0(std::async(std::launch::async,tsk1,std::ref(sf)));
		std::future<void>f1(std::async(std::launch::async,tsk1,std::ref(sf)));
		std::future<void>f2(std::async(std::launch::async,tsk1,std::ref(sf)));
		std::future<void>f3(std::async(std::launch::async,tsk1,std::ref(sf)));
		f0.get();
		f1.get();
		f2.get();
		f3.get();
	}catch(const std::exception&e){
		std::cerr<<"error:main:"<<e.what()<<std::endl;
	}
	return EXIT_SUCCESS;
}
