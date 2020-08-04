#include<iostream>
#include<cstdlib>
#include<ctime>
int main(int argc,char** argv){
	//basic examples
	{
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
	{
		srand(time(0));
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
	{
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
	return 0;
}
