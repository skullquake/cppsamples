/*
 * the timed_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.
 * in a mannger similar to mutex, timed_mutex offers exclusive, non-recursive ownership semantics.
 * in addition, timed_mutex provides the ability to attempt to claim ownership of a timed_mutex with a timeout via try_lock_for() and try_lock_until()
 *
 * references:
 *   cppreference/reference/en/cpp/thread/timed_mutex.html
 *   The C++ Standard Library - Nicolai M. Josuttis - Chapter 18 - Concurrency
 */
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<cstdlib>
int main(void){
	{
		int i=42;
		std::timed_mutex tm;
		std::thread t([&tm,&i](){
			std::cout<<"info:"<<std::this_thread::get_id()<<":begin"<<std::endl;
			try{
				std::lock_guard<std::timed_mutex>lg(tm);
				std::cout<<"info:"<<std::this_thread::get_id()<<":locked"<<std::endl;
				i=24;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}catch(const std::exception&e){
				std::cerr<<"error:"<<std::this_thread::get_id()<<":failed to acquire lock:"<<e.what()<<std::endl;
			}catch(...){
				std::cerr<<"error:"<<std::this_thread::get_id()<<":failed to acquire lock"<<std::endl;
			}
			std::cout<<"info:"<<std::this_thread::get_id()<<":end"<<std::endl;
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		if(tm.try_lock_for(std::chrono::milliseconds(250))){
			std::cout<<"info:main:locked"<<std::endl;
			tm.unlock();
		}else{
			std::cerr<<"error:main:failed to acquire lock"<<std::endl;
		}
		t.join();
	}
	return EXIT_SUCCESS;
}
