#include<utility>
#include<iostream>
int main(int argc,char** argv){
	{
		int a=0;
		int b=1;
		std::cout<<"["<<a<<":"<<b<<"]"<<std::endl;
		std::swap(a,b);
		std::cout<<"["<<a<<":"<<b<<"]"<<std::endl;
	}
	{
		std::string a("foo");
		std::string b("bar");
		std::cout<<"["<<a<<":"<<b<<"]"<<std::endl;
		std::swap(a,b);
		std::cout<<"["<<a<<":"<<b<<"]"<<std::endl;
	}

	return 0;
}
