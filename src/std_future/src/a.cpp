/*
 * observe threads and time
 *	/usr/bin/time ./a.out 0
 *	vs
 *	/usr/bin/time ./a.out 1
 */
#include<iostream>
#include<chrono>
#include<algorithm>
#include<set>
#include<random>
#include<cstdlib>
#include<future>
#include<thread>
#include<vector>
#define NELEM 1000000
#define NITR 8
void t0();
void t1();
int test0(int,char**);
void test1();
void test2();
void test3();
int main(int argc,char**argv){
	//test0(argc,argv);
	test1();
	test2();
	test3();
}
void t0(){
	std::cout<<"t0():start\n";
	auto fn=[](const size_t nel){
		std::random_device r;
		std::mt19937 g(r());
		std::uniform_int_distribution<int>d(0,nel*2);
		std::set<int>s;
		std::generate_n(std::inserter(s,s.end()),nel,[&](){return d(g);});
		return s;
	};
	std::vector<std::set<int>>vs;
	for(std::size_t i=0;i<NITR;++i){
		vs.push_back(fn(NELEM));
	}
	std::for_each(vs.begin(),vs.end(),[](std::set<int>&s){
		std::cout<<s.size()<<'\n';
	});
	std::cout<<"t0():end\n";
}
void t1(){
	std::cout<<"t1():start\n";
	auto fn=[](const size_t nel){
		std::random_device r;
		std::mt19937 g(r());
		std::uniform_int_distribution<int>d(0,nel*2);
		std::set<int>s;
		std::generate_n(std::inserter(s,s.end()),nel,[&](){return d(g);});
		return s;
	};
	std::vector<std::future<std::set<int>>>vf;
	for(std::size_t i=0;i<NITR;++i){
		vf.push_back(std::async(fn,NELEM));
	}
	std::for_each(vf.begin(),vf.end(),[](std::future<std::set<int>>&f){
		f.wait();
	});
	std::for_each(vf.begin(),vf.end(),[](std::future<std::set<int>>&f){
		std::set<int>s=f.get();
		std::cout<<s.size()<<'\n';
	});
	std::cout<<"t1():end\n";
}
int test0(int argc,char**argv){
	int ret=EXIT_SUCCESS;
	if(argc==2){
		try{
			int opt=std::stoi(argv[1]);
			switch(opt){
				case 0:
					t0();
					break;
				case 1:
					t1();
					break;
				default:
					std::cerr<<"Invalid option\n";
					ret=EXIT_FAILURE;
					break;
			}
		}catch(std::exception e){
			std::cerr<<"Error: "<<e.what()<<'\n';
			ret=EXIT_FAILURE;
		}
	}else{
		std::cerr<<"Invalid options\n";
		ret=EXIT_FAILURE;
	}
	return ret;
}
void test1(){
	std::cout<<
		std::future<int>(std::async([]()->int{return 42;})).get()+
		std::future<int>(std::async([]()->int{return 24;})).get()
		<<std::endl
	;
}
void test2(){
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::cout<<
		std::future<int>(std::async([]()->int{
			std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
			return 42;
		})).get()+
		std::future<int>(std::async([]()->int{
			std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
			return 24;
		})).get()
		<<std::endl
	;
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count()<<"[µs]"<<std::endl;
	std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<"[ns]"<<std::endl;
}
void test3(){
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::future<int> as0(std::async([]()->int{
			std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
			return 42;
	}));
	std::future<int> as1(std::async([]()->int{
		std::cout<<"tid:"<<std::this_thread::get_id()<<":start"<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout<<"tid:"<<std::this_thread::get_id()<<":end"<<std::endl;
		return 24;
	}));
	std::cout<<
		as0.get()+
		as1.get()
		<<std::endl
	;
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count()<<"[µs]"<<std::endl;
	std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<"[ns]"<<std::endl;
}
