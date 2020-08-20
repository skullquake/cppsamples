/*
 * the recursive_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads
 *
 * references:
 *   cppreference/reference/en/cpp/thread/recursive_mutex.html		
 *   The C++ Standard Library - Nicolai M. Josuttis - Chapter 18 - Concurrency
 */
#include<iostream>
#include<thread>
#include<mutex>
#include<random>
#include<chrono>
#include<cstdlib>
int main(void){
	{//basic
		int i=42;
		std::recursive_mutex rm;
		rm.lock();
		i=24;
		rm.unlock();
		std::cout<<i<<std::endl;
	}
	{//with std::lock_guard
		int i=42;
		std::recursive_mutex rm;
		{
			std::lock_guard<std::recursive_mutex>lg(rm);
			i=24;
		}
		std::cout<<i<<std::endl;
	}
	{
		class C{
			public:
				C():mi(0){
					std::cout<<"info:C::C()"<<std::endl;
				};
				void f0(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:C::f0()"<<std::endl;
					++mi;
				};
				void f1(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:C::f1()"<<std::endl;
					--mi;
				};
				void f2(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:C::f2()"<<std::endl;
					f0();
					f1();
				};
			private:
				int mi;
				std::recursive_mutex mm;
		}c;
		c.f0();
		c.f1();
		c.f2();
	}
	{//with threads
		class C{
			public:
				C():mi(0){
					std::cout<<"info:"<<std::this_thread::get_id()<<":C::C()"<<std::endl;
				};
				void f0(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:"<<std::this_thread::get_id()<<":C::f0()"<<std::endl;
					++mi;
					std::default_random_engine dre;
					std::uniform_int_distribution<int>uid(50,100);
					std::this_thread::sleep_for(std::chrono::milliseconds(uid(dre)));
				};
				void f1(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:"<<std::this_thread::get_id()<<":C::f1()"<<std::endl;
					--mi;
					std::default_random_engine dre;
					std::uniform_int_distribution<int>uid(50,100);
					std::this_thread::sleep_for(std::chrono::milliseconds(uid(dre)));
				};
				void f2(){
					std::lock_guard<std::recursive_mutex>lg(mm);
					std::cout<<"info:"<<std::this_thread::get_id()<<":C::f2()"<<std::endl;
					f0();
					f1();
					std::default_random_engine dre;
					std::uniform_int_distribution<int>uid(50,100);
					std::this_thread::sleep_for(std::chrono::milliseconds(uid(dre)));
				};
			private:
				int mi;
				std::recursive_mutex mm;
		}c;
		std::thread t0([&c](){
			for(size_t i=0;i<4;++i){
				c.f0();
				c.f1();
				c.f2();
			}
		});
		std::thread t1([&c](){
			for(size_t i=0;i<4;++i){
				c.f0();
				c.f1();
				c.f2();
			}
		});
		t0.join();
		t1.join();
	}
	return EXIT_SUCCESS;
}
