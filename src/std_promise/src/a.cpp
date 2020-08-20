/*
 * std::promise object is the counterpart of a std:future
 * a std::promise can hold a shared state, representing a result or an exception
 * a std::future allows you to retrieve data using the get() method
 * a std::promise enabled you to provide the data using the std() method
 *
 * references:
 *   cppreference/reference/en/cpp/thread/promise.html
 *   The C++ Standard Library - Nicolai M. Josuttis - Chapter 18 - Concurrency
 */
#include<iostream>
#include<thread>
#include<future>
#include<cstdlib>
int main(void){
	try{//basic usage
		int i{42};
		std::promise<int>p;						//default constructor. constructs the promise with an empty shared state
		p.set_value(std::move(i));					//atomically store value into the shared state and make the state ready
		std::future<int> f=p.get_future();				//returns a future object associated with the same shared state as *this
		std::cout<<f.get()<<std::endl;
	}catch(const std::exception&e){std::cerr<<"error:"<<e.what()<<std::endl;
	}catch(...){std::cerr<<"error:NULL"<<std::endl;}
	try{
		std::promise<int>p;						//default constructor. constructs the promise with an empty shared state
		std::thread t([](std::promise<int>&p){
			try{
				int i{42};
				p.set_value(std::move(i));			//atomically store value into the shared state and make the state ready
			}catch(...){
				p.set_exception(std::current_exception());	//propagate exception
			}
		},std::ref(p));
		t.detach();
		std::future<int> f=p.get_future();				//returns a future object associated with the same shared state as *this
		std::cout<<f.get()<<std::endl;					//waits until the future has a valie result
	}catch(const std::exception&e){std::cerr<<"error:"<<e.what()<<std::endl;
	}catch(...){std::cerr<<"error:NULL"<<std::endl;}
	return EXIT_SUCCESS;
}
