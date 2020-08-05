/*
 * observe threads and time
 *	/usr/bin/time ./a.out 0
 *	vs
 *	/usr/bin/time ./a.out 1
 */
#include<iostream>
#include<algorithm>
#include<set>
#include<random>
#include<cstdlib>
#include<future>
#include<vector>
#define NELEM 1000000
#define NITR 8
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
int main(int argc,char**argv){
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
					break;
			}
		}catch(std::exception e){
			std::cerr<<"Error: "<<e.what()<<'\n';
		}
	}else{
		std::cerr<<"Invalid options\n";
	}
	return EXIT_SUCCESS;
}
