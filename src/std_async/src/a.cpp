#include<iostream>
#include<chrono>
#include<future>
#include<cstdlib>
int main(void){
	{
		std::future<void> f0(std::async([](){}));
		f0.get();
	}
	{
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
	}
	return EXIT_SUCCESS;
}
