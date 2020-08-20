#include<iostream>
#include<chrono>
#include<future>
#include<cstdlib>
class C{
	public:
		C(){std::cout<<"C::C()"<<std::endl;};
		~C(){std::cout<<"C::~C()"<<std::endl;};
		void f(){std::cout<<"C::f()"<<std::endl;};
		void fi(int i){std::cout<<"C::f():"<<i<<std::endl;};
	private:
};
int main(void){
	{//lambda
		std::future<void> f0(std::async([](){}));
		f0.get();
	}
	{//lambda
		std::chrono::steady_clock::time_point begin=std::chrono::steady_clock::now();
		std::future<void> f0(std::async([](){
			std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
		}));
		std::future<void> f1(std::async([](){
			std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
		}));
		f0.get();
		f1.get();
		std::chrono::steady_clock::time_point end=std::chrono::steady_clock::now();
		std::cout
		    <<std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count()
		    <<"[µs]"
		    <<std::endl;
		std::cout
		    <<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()
		    <<"[ns]"
		    <<std::endl;
	}
	{//launch policy
		try{
			std::future<void> f0(std::async(std::launch::async,[](){}));
			f0.get();
		}catch(...){
			std::cerr<<"error:failed to start async"<<std::endl;
		}
		try{
			std::future<void> f0(std::async(std::launch::deferred,[](){}));
			f0.get();
		}catch(...){
			std::cerr<<"error:failed to start async"<<std::endl;
		}
	}
	{//exceptions
		try{
			std::cout<<"info:1"<<std::endl;
			std::future<void>f0(std::async([](){
				std::cout<<"info:2"<<std::endl;
				throw 42;
				std::cout<<"info:3"<<std::endl;
			}));
			std::cout<<"info:4"<<std::endl;
			f0.get();
			std::cout<<"info:5"<<std::endl;
		}catch(...){
			std::cerr<<"error:catch"<<std::endl;
		}

	}
	{//wait_until - timeouts
		bool endlambda=false;
		std::future<void>f(std::async(std::launch::async,[&](){
			for(size_t i=0;i<10&&!endlambda;++i){
				std::cout<<"info:lambda:processing:["<<i<<"]"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}));
		//do extra work here, e.g. less accurate computation
		std::future_status s=f.wait_until(std::chrono::system_clock::now()+std::chrono::milliseconds(500));
		endlambda=true;//inform end
		if(s==std::future_status::ready){
			std::cout<<"info:completed in time"<<std::endl;
		}else{
			std::cerr<<"error:not completed in time"<<std::endl;
		}
	}
	{//wait_until - polling example
		std::future<void>f(std::async(std::launch::async,[&](){
			for(size_t i=0;i<10;++i){
				std::cout<<"info:lambda::processing["<<i<<"]"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}));
		size_t i=0;
		while(f.wait_for(std::chrono::seconds(0))!=std::future_status::ready){
			std::cout<<"info:main::processing["<<i<<"]"<<std::endl;
			++i;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		f.get();
	}
	{//yield
		std::future<void>f(std::async(std::launch::async,[&](){
			for(size_t i=0;i<10;++i){
				std::cout<<"info:lambda::processing["<<i<<"]"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}));
		while(f.wait_for(std::chrono::seconds(0))!=std::future_status::ready){
			std::this_thread::yield();//hits reschedule to next thread and/or sleep for a short period of time
		}
		f.get();

	}
	{//async member function
		C c;
		{
			std::future<void> f(std::async(&C::f,c));
			f.get();
		}
		{
			std::future<void> f(std::async(&C::fi,c,42));
			f.get();
		}
	}
	return EXIT_SUCCESS;
}
