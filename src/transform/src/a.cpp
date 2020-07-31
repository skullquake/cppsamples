#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdlib>
int main(void){
	std::vector<int>v{0,1,2,3};
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),[](const int&a){return a+1;});
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),[](const int&a){return a-1;});
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind([](const int&a,const int&b){return a+b;},std::placeholders::_1,10));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind([](const int&a,const int&b){return a-b;},std::placeholders::_1,10));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,10));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,10));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(std::plus<int>(),10,std::bind(std::multiplies<int>(),std::placeholders::_1,2)));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(std::divides<int>(),std::bind(std::minus<int>(),std::placeholders::_1,10),2));
	std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	{
		std::vector<int>v{0,1,2,3};
		auto b=std::bind([](int a,int b)->int{return a-b;},std::bind([](int a,int b)->int{return a+b;},std::placeholders::_1,std::placeholders::_2),std::placeholders::_3);
		std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
		std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(b,1,2,std::placeholders::_1));
		std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
	}
	{
		auto add=[](int a,int b)->int{return a+b;};
		auto sub=[](int a,int b)->int{return a-b;};
		auto mul=[](int a,int b)->int{return a*b;};
		auto div=[](int a,int b)->int{return a/b;};
		{//a+1-2
			std::vector<int>v{0,1,2,3};
			auto b=std::bind(sub,std::bind(add,std::placeholders::_1,std::placeholders::_2),std::placeholders::_3);
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
			std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(b,1,2,std::placeholders::_1));
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
		}
		{//a+1*2
			std::vector<int>v{0,1,2,3};
			auto b=std::bind(mul,std::bind(add,std::placeholders::_1,std::placeholders::_2),std::placeholders::_3);
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
			std::transform(v.cbegin(),v.cend(),v.begin(),std::bind(b,1,2,std::placeholders::_1));
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
		}
		{//a+a*a
			std::vector<int>v{0,1,2,3};
			auto b=std::bind(mul,std::bind(add,std::placeholders::_1,std::placeholders::_1),std::placeholders::_1);
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
			std::transform(v.cbegin(),v.cend(),v.begin(),b);
			std::for_each(v.begin(),v.end(),[](const int&a){std::cout<<a<<" ";});std::cout<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
