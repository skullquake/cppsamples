/*
 * thread pools can control when and how many background tasks run simultaneously
 * std::packaged_Task wraps any callable target (function,lambda,bind expression,functor) so that it can be invoked asynchronously.
 * its return value or exception thrown is stored in a shared state which can be accessed through std::future object
 *
 * references:
 *   cppreference/reference/en/cpp/thread/packaged_task.html
 *   The C++ Standard Library - Nicolai M. Josuttis - Chapter 18 - Concurrency
 */
#include<iostream>
#include<thread>
#include<future>
#include<chrono>
#include<cstdlib>
int main(void){
	{//non-threaded
		std::packaged_task<int(int)> pt([](int a)->int{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			return a+42;
		});//create task
		std::future<int>f=pt.get_future();//get packaged task future
		pt(24);//start task
		std::cout<<f.get()<<std::endl;//get value from packaged task future
	}
	{//threaded
		std::packaged_task<int(int)> pt([](int a)->int{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			return a+42;
		});//create task
		std::future<int>f=pt.get_future();//get packaged task future
		std::thread t(std::move(pt),24);//create thread
		t.join();//join thread
		std::cout<<f.get()<<std::endl;//get value from packaged task future
	}
	return EXIT_SUCCESS;
}
