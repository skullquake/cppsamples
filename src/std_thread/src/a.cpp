#include<iostream>
#include<iomanip>
#include<random>
#include<thread>
#include<vector>
#include<chrono>
#include<algorithm>
#include<iterator>
#include<cstdlib>
void f(int);
class C{
	public:
		void operator()(int a);
};
int main(void){
	{
		std::vector<std::thread>vt;
		//function
		vt.push_back(std::thread(f,24));
		//function object
		vt.push_back(std::thread(C(),24));
		//lambda
		vt.push_back(std::thread([](int a){
			std::default_random_engine dre(std::random_device{}());
			std::uniform_int_distribution<unsigned int>d(0,1000);
			std::this_thread::sleep_for(std::chrono::milliseconds(d(dre)));
			std::cout<<"lambda:       "<<a<<'\n';
		},24));
		for(auto&a:vt){
			a.join();
		}
	}
	{//catching exceptions in threads
		std::thread t([](){
			try{
				for(size_t i=0;i<8;++i){
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					std::cout<<"info:["<<std::this_thread::get_id()<<"]:"<<i<<std::endl;
				}
				throw 42;
			}catch(const std::exception&e){
				std::cerr<<"error:["<<std::this_thread::get_id()<<"]:"<<e.what()<<std::endl;
			}catch(...){
				std::cerr<<"error:["<<std::this_thread::get_id()<<"]:"<<"NULL"<<std::endl;
			}
		});
		t.join();
	}
	{//detaching threads
		std::thread t([](){
			try{
				for(size_t i=0;i<8;++i){
					std::cout<<"info:["<<std::this_thread::get_id()<<"]:"<<i<<std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
				throw 42;
			}catch(const std::exception&e){
				std::cerr<<"error:["<<std::this_thread::get_id()<<"]:"<<e.what()<<std::endl;
			}catch(...){
				std::cerr<<"error:["<<std::this_thread::get_id()<<"]:"<<"NULL"<<std::endl;
			}
		});
		t.detach();//detached thread continues in background (until program termination)
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	{//detached threads - passing arguments 
		{//references - potentially dangerous
			{
				int a=0;
				std::cout<<"info:main:a in scope"<<std::endl;
				std::thread t([&](){
					try{
						for(size_t i=0;i<32;++i){
							std::cout<<"info:ref:["<<std::this_thread::get_id()<<"]:"<<a<<std::endl;
							++a;
							std::this_thread::sleep_for(std::chrono::milliseconds(100));
						}
						throw 42;
					}catch(const std::exception&e){
						std::cerr<<"error:ref:["<<std::this_thread::get_id()<<"]:"<<e.what()<<std::endl;
					}catch(...){
						std::cerr<<"error:ref:["<<std::this_thread::get_id()<<"]:"<<"NULL"<<std::endl;
					}
				});
				t.detach();//detached thread continues in background until program termination
			}
			std::cout<<"info:main:a out of scope"<<std::endl;
			//a now out of scope
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		{//pass by value (local copies) - potentially safer
			int a=0;
			std::thread t([](int a){
				try{
					for(size_t i=0;i<32;++i){
						std::cout<<"info:val:["<<std::this_thread::get_id()<<"]:"<<a<<std::endl;
						++a;
						std::this_thread::sleep_for(std::chrono::milliseconds(100));
					}
					throw 42;
				}catch(const std::exception&e){
					std::cerr<<"error:val:["<<std::this_thread::get_id()<<"]:"<<e.what()<<std::endl;
				}catch(...){
					std::cerr<<"error:val:["<<std::this_thread::get_id()<<"]:"<<"NULL"<<std::endl;
				}
			},a);
			t.detach();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
	{//thread ids
		std::thread t0([](){
			std::thread::id id=std::this_thread::get_id();
			std::cout<<"info:[0]:thread_id:"<<id<<std::endl;
		});
		std::thread t1([](){
			std::thread::id id=std::this_thread::get_id();
			std::cout<<"info:[1]thread_id:"<<id<<std::endl;
		});

		std::thread::id id0=t0.get_id();
		std::thread::id id1=t1.get_id();
		std::cout<<"info:[0]:thread_id:"<<id0<<std::endl;
		std::cout<<"info:[1]:thread_id:"<<id1<<std::endl;
		std::cout<<"info:main:thread_id:"<<std::thread::id()<<std::endl;
		std::cout<<"info:main:thread_id:"<<std::this_thread::get_id()<<std::endl;
		//other allowed operations: comparison
		std::cout<<"info:cmp:id0==id1:"<<std::boolalpha<<(id0==id1)<<std::endl;
		t0.join();
		t1.join();
	}
	{//concurrent access - no mutexes
		std::vector<int>v{2,2,2,2,2,2,2,2,2};
		std::thread t0([](std::vector<int>&v){

			std::default_random_engine dre(std::random_device{}());
			std::uniform_int_distribution<unsigned int>d(0,10);
			std::for_each(v.begin(),v.end(),[&dre,&d](int&e){
				std::this_thread::sleep_for(std::chrono::milliseconds(d(dre)));
				e+=1;
			});
		},std::ref(v));
		std::thread t1([](std::vector<int>&v){
			std::default_random_engine dre(std::random_device{}());
			std::uniform_int_distribution<unsigned int>d(0,10);
			std::for_each(v.begin(),v.end(),[&dre,&d](int&e){
				std::this_thread::sleep_for(std::chrono::milliseconds(d(dre)));
				e*=2;
			});

		},std::ref(v));
		t0.join();
		t1.join();
		//multiple runs will indicate inconsistent output
		std::copy(v.cbegin(),v.cend(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
void f(int a){
	std::default_random_engine dre(std::random_device{}());
	std::uniform_int_distribution<unsigned int>d(0,1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(d(dre)));
	std::cout<<"function:     "<<a<<'\n';
}
void C::operator()(int a){
	std::default_random_engine dre(std::random_device{}());
	std::uniform_int_distribution<unsigned int>d(0,1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(d(dre)));
	std::cout<<"C::operator():"<<a<<'\n';
}
