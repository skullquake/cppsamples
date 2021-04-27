#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<thread>
#include<unistd.h>
int main(int argc,char** argv){
	{//basic examples
		auto a=[](){
			std::cout<<"test"<<std::endl;
		};
		a();
		[](){
			std::cout<<"test2"<<std::endl;
		}();
		int b=1234;
		[&](){
			std::cout<<b<<std::endl;
		}();
		[b](){
			std::cout<<b<<std::endl;
		}();
		[&b](){
			std::cout<<b<<std::endl;
		}();
	}
	//specifying return-type
	{
		std::cout<<[]()->int{return 0;}()<<std::endl;;
	}
	srand(time(0));
	{//in loops
		for(;[]()->bool{
			int r=rand();
			std::cout<<r<<std::endl;
			return r%2==0;
		}(););
		while([]()->bool{
			int r=rand();
			std::cout<<r<<std::endl;
			return r%2==0;
		}());
		do{}while([]()->bool{
			int r=rand();
			std::cout<<r<<std::endl;
			return r%2==0;
		}());
	}
	{//pad out for loop
		for(int i=[&]()->int{
			std::cout<<"init: "<<i<<std::endl;
			return 0;
		}();[&]()->bool{
			std::cout<<"test: "<<i<<std::endl;
			return i!=8;
		}();[&]()->void{
			++i;
			std::cout<<"inc:  "<<i<<std::endl;
		}())[](){}();
	}
	{//vector
		std::vector<void(*)(void)> vf{
			[](){std::cout<<"f0"<<std::endl;},
			[](){std::cout<<"f1"<<std::endl;},
			[](){std::cout<<"f2"<<std::endl;},
			[](){std::cout<<"f3"<<std::endl;}
		};
		std::for_each(vf.begin(),vf.end(),[](auto&f){f();});
	}
	{//vector
		std::vector<void(*)(void)> vf{
			[](){usleep(((rand()%1000)*1000));std::cout<<"f0"<<std::endl;},
			[](){usleep(((rand()%1000)*1000));std::cout<<"f1"<<std::endl;},
			[](){usleep(((rand()%1000)*1000));std::cout<<"f2"<<std::endl;},
			[](){usleep(((rand()%1000)*1000));std::cout<<"f3"<<std::endl;}
		};
		std::vector<std::thread>vt;
		std::for_each(vf.begin(),vf.end(),[&vt](auto f){vt.push_back(std::thread(f));});
		std::for_each(vt.begin(),vt.end(),[](auto&t){t.join();});
	}
	{//mutable
		auto a=42;
		[a]()mutable->void{
			auto b=a;//with mutable you can assign
		};
	}
	{//mutable
		auto a=42;
		[=]()mutable->void{
			auto b=a;//with mutable you can assign
		};
	}
	return 0;
}
