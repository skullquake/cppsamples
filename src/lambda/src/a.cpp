#include<iostream>
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
	return 0;
}
