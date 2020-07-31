#include<iostream>
#include<functional>
#include<cstdlib>
int main(void){
	{
		std::cout<<std::bind(std::plus<int>(),4,2)()<<std::endl;
		std::cout<<std::bind(std::minus<int>(),4,2)()<<std::endl;
		std::cout<<std::bind(std::negate<int>(),42)()<<std::endl;
		std::cout<<std::bind(std::divides<int>(),4,2)()<<std::endl;
		std::cout<<std::bind(std::modulus<int>(),4,2)()<<std::endl;
		std::cout<<std::bind(std::modulus<int>(),2,4)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::logical_or<bool>(),true,false)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::logical_and<bool>(),true,false)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::logical_not<bool>(),true)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::equal_to<bool>(),1,1)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::not_equal_to<bool>(),1,1)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::greater<bool>(),1,2)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::less<bool>(),1,2)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::less_equal<bool>(),1,2)()<<std::endl;
		std::cout<<std::boolalpha<<std::bind(std::greater_equal<bool>(),1,2)()<<std::endl;
	}
	{
		auto add10=std::bind(std::plus<int>(),std::placeholders::_1,10);
		std::cout<<add10(42)<<std::endl;
	}
	{
		auto bf=std::bind([](int a){std::cout<<a<<std::endl;},42);
		bf();
	}
	{
		auto bf=std::bind([](int a,int b){std::cout<<a+b<<std::endl;},std::placeholders::_1,42);
		bf(24);
	}
	{
		auto bf=std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},std::placeholders::_2,std::placeholders::_1);
		bf(1,2);
	}
	{
		auto bf=std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},1,2);
		bf();
	}
	{
		auto bf=std::bind([](int a,int b,int c){std::cout<<"["<<a<<","<<b<<","<<c<<"]"<<std::endl;},std::placeholders::_1,std::placeholders::_2,1);
		bf(2,3);
	}
	{
		auto bf=std::bind([](int a,int b,int c){std::cout<<"["<<a<<","<<b<<","<<c<<"]"<<std::endl;},std::placeholders::_3,std::placeholders::_2,std::placeholders::_1);
		bf(1,2,3);
	}
	{
		auto bf=std::bind([](int a,int b,int c){std::cout<<"["<<a<<","<<b<<","<<c<<"]"<<std::endl;},1,std::placeholders::_1,2);
		bf(3);
	}
	return EXIT_SUCCESS;
}
