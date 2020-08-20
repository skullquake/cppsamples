/*
 * the mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads
 * a mutex, or mutual exclusion, is an object that helps to control the concurrent access of a resource by providing exclusive access to it
 *
 * references:
 *   cppreference/reference/en/cpp/thread/mutex.html
 *   The C++ Standard Library - Nicolai M. Josuttis - Chapter 18 - Concurrency
 */
#include<iostream>
#include<thread>
#include<future>
#include<mutex>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cstdlib>
int main(void){
	{//mutex - basic usage
		int i=42;
		std::mutex m;
		m.lock();
		std::cout<<i<<std::endl;
		m.unlock();
	}
	{//not using mutex - potential interleaved output
		std::vector<int>v{1,1,1,1};
		std::thread t0([](std::vector<int>&v){
			std::for_each(v.begin(),v.end(),[](const int&e){
				std::cout<<std::this_thread::get_id()<<" "<<e<<std::endl;
			});
		},std::ref(v));
		std::thread t1([](std::vector<int>&v){
			std::for_each(v.begin(),v.end(),[](const int&e){
				std::cout<<std::this_thread::get_id()<<" "<<e<<std::endl;
			});
		},std::ref(v));
		t0.join();
		t1.join();
	}
	{//using mutex - noninterleaved output
		std::vector<int>v{1,1,1,1};
		std::mutex m;
		std::thread t0([&m](std::vector<int>&v){
			m.lock();
			std::for_each(v.begin(),v.end(),[](const int&e){
				std::cout<<std::this_thread::get_id()<<" "<<e<<std::endl;
			});
			m.unlock();
		},std::ref(v));
		std::thread t1([&m](std::vector<int>&v){
			m.lock();
			std::for_each(v.begin(),v.end(),[](const int&e){
				std::cout<<std::this_thread::get_id()<<" "<<e<<std::endl;
			});
			m.unlock();
		},std::ref(v));
		t0.join();
		t1.join();
	}
	{//dealing with exceptions using std::lock_guard - the standard library provides std::lock_guard to provide raii locking/unlocking
		int i=42;
		std::mutex m;
		try{
			std::cout<<"info:section1:locking"<<std::endl;
			std::lock_guard<std::mutex>lg(m);//automatically lock/unlock
			std::cout<<"info:section1:i:"<<i<<std::endl;
			i=24;
			std::cout<<"info:section1:i:"<<i<<std::endl;
			std::cout<<"info:section1:unlocking"<<std::endl;
		}catch(const std::exception&e){
			std::cout<<"error:section1:error:"<<e.what()<<std::endl;
		}catch(...){
			std::cout<<"error:section1:error:NULL"<<std::endl;
		}
		try{
			std::cout<<"info:section2:locking"<<std::endl;
			std::lock_guard<std::mutex>lg(m);//automatically lock/unlock
			std::cout<<"info:section2:i:"<<i<<std::endl;
			i=42;
			std::cout<<"info:section2:i:"<<i<<std::endl;
			std::cout<<"info:section2:unlocking"<<std::endl;
		}catch(const std::exception&e){
			std::cout<<"error:2:error:"<<e.what()<<std::endl;
		}catch(...){
			std::cout<<"error:2:error:NULL"<<std::endl;
		}
	}
	{//std::lock_guard - threaded
		int i=42;
		std::mutex m;
		std::thread t0([&m,&i](){
			try{
				std::cout<<"info:"<<std::this_thread::get_id()<<":locking"<<std::endl;
				std::lock_guard<std::mutex>lg(m);//automatically lock/unlock
				std::cout<<"info:"<<std::this_thread::get_id()<<":i:"<<i<<std::endl;
				i=42;
				std::cout<<"info:"<<std::this_thread::get_id()<<":i:"<<i<<std::endl;
				std::cout<<"info:"<<std::this_thread::get_id()<<":unlocking"<<std::endl;
			}catch(const std::exception&e){
				std::cout<<"error:"<<std::this_thread::get_id()<<":error:"<<e.what()<<std::endl;
			}catch(...){
				std::cout<<"error:"<<std::this_thread::get_id()<<":error:NULL"<<std::endl;
			}
		});
		std::thread t1([&m,&i](){
			try{
				std::cout<<"info:"<<std::this_thread::get_id()<<":locking"<<std::endl;
				std::lock_guard<std::mutex>lg(m);//automatically lock/unlock
				std::cout<<"info:"<<std::this_thread::get_id()<<":i:"<<i<<std::endl;
				i=42;
				std::cout<<"info:"<<std::this_thread::get_id()<<":i:"<<i<<std::endl;
				std::cout<<"info:"<<std::this_thread::get_id()<<":unlocking"<<std::endl;
			}catch(const std::exception&e){
				std::cout<<"error:"<<std::this_thread::get_id()<<":error:"<<e.what()<<std::endl;
			}catch(...){
				std::cout<<"error:"<<std::this_thread::get_id()<<":error:NULL"<<std::endl;
			}
		});
		t0.join();
		t1.join();
	}
	{//std::lock_guard - in context of futures
		std::vector<int>v;
		std::mutex m;
		std::future<void>f0(std::async(std::launch::async,[&m,&v](){
			std::lock_guard<std::mutex>lg(m);
			std::cout<<"info:"<<std::this_thread::get_id()<<":start"<<std::endl;
			for(size_t i=0;i<4;++i)
				v.push_back(i);
			std::cout<<"info:"<<std::this_thread::get_id()<<":end"<<std::endl;
		}));
		std::future<void>f1(std::async(std::launch::async,[&m,&v](){
			std::lock_guard<std::mutex>lg(m);
			std::cout<<"info:"<<std::this_thread::get_id()<<":start"<<std::endl;
			for(size_t i=0;i<4;++i)
				v.push_back(i);
			std::cout<<"info:"<<std::this_thread::get_id()<<":end"<<std::endl;
		}));
		f0.wait();
		f1.wait();
		f0.get();
		f1.get();
		std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	}
	{//try_lock - basic
		int i=42;
		std::cout<<i<<std::endl;
		std::mutex m;
		m.try_lock();
		i=24;
		m.unlock();
		std::cout<<i<<std::endl;
	}
	{//try_lock - thread
		int i=42;
		std::cout<<"info:main:i:"<<i<<std::endl;
		std::cout<<i<<std::endl;
		std::mutex m;
		std::thread t([&m,&i](){
			if(m.try_lock()){
				std::cout<<"info:"<<std::this_thread::get_id()<<":locked"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				i=24;
				m.unlock();
			}else{
				std::cout<<"error:"<<std::this_thread::get_id()<<":failed to lock"<<std::endl;
			}
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(m.try_lock()){
			std::cout<<"info:main:locked"<<std::endl;
			i=48;
			m.unlock();
		}else{
			std::cout<<"error:main:failed to lock"<<std::endl;
		}
		t.join();
		std::cout<<"info:main:i:"<<i<<std::endl;
	}
	//to wait for a particular amount of time, you can use a std::timed_mutex
	{//std::timed_mutex try_lock_for - basic
		int i=42;
		std::cout<<"info:main:i:"<<i<<std::endl;
		std::timed_mutex m;
		m.try_lock_for(std::chrono::milliseconds(100));
		i=24;
		m.unlock();
		std::cout<<"info:main:i:"<<i<<std::endl;
	}
	{//std::timed_mutex try_lock_for - thread
		int i=42;
		std::cout<<"info:main:i:"<<i<<std::endl;
		std::timed_mutex tm;
		std::thread t([&tm,&i](){
			if(tm.try_lock()){
				std::cout<<"info:"<<std::this_thread::get_id()<<":locked"<<std::endl;
				i=24;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				tm.unlock();
			}else{
				std::cout<<"error:"<<std::this_thread::get_id()<<":failed to lock"<<std::endl;
			}
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(tm.try_lock_for(std::chrono::milliseconds(100))){
			std::cout<<"info:main:locked"<<std::endl;
			i=42;
			tm.unlock();
		}else{
			std::cout<<"error:main:failed to lock"<<std::endl;
		}
		t.join();
		std::cout<<"info:main:i:"<<i<<std::endl;
	}
	{//todo: try_lock_until - basic
		int i=42;
		std::timed_mutex tm;
		tm.try_lock_until(std::chrono::system_clock::now()+std::chrono::milliseconds(1000));
		i=24;
		tm.unlock();
		i=42;
	}
	{//try_lock_until - thread
		int i=42;
		std::timed_mutex tm;
		std::thread t([&tm,&i](){
			std::cout<<"info:"<<std::this_thread::get_id()<<":start"<<std::endl;
			try{
				std::lock_guard<std::timed_mutex>lg(tm);
				std::cout<<"info:"<<std::this_thread::get_id()<<":locked"<<std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}catch(const std::exception&e){
				std::cout<<"error:"<<std::this_thread::get_id()<<":"<<e.what()<<std::endl;
			}catch(...){
				std::cout<<"error:"<<std::this_thread::get_id()<<":NULL"<<std::endl;
			}
			std::cout<<"info:"<<std::this_thread::get_id()<<":end"<<std::endl;
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(tm.try_lock_until(std::chrono::system_clock::now()+std::chrono::milliseconds(500))){
			std::cout<<"info:main:locked"<<std::endl;
		}else{
			std::cout<<"error:main:not locked"<<std::endl;
		}
		t.join();
	}
	{//std::recursive_timed_mutex
	}
	return EXIT_SUCCESS;
}
