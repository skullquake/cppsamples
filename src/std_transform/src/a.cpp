#include<iostream>
#include<vector>
#include<map>
#include<functional>
#include<cstdlib>
char fnup(char c){
	return ::toupper(c);
}
char fnlo(char c){
	return ::tolower(c);
}
//--------------------------------------------------------------------------------
//class for class member function functor test
//--------------------------------------------------------------------------------
class A{
	public:
		A(int maP):ma(maP){};
		int get_ma()const{return this->ma;};
	private:
		int ma;
};
//--------------------------------------------------------------------------------
//end class
//--------------------------------------------------------------------------------
int main(int argc,char** argv){
	//std::string example
	{
		std::string data="Lorem Ipsum Sit Consecutar Dolor Amet";
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),::tolower);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),::toupper);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),fnlo);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),fnup);
		std::cout<<data<<std::endl;

		int idx=0;
		std::transform(data.begin(),data.end(),data.begin(),[&](char&c){
				return idx++%2?char(::tolower(c)):char(::toupper(c));
		});
		std::cout<<data<<std::endl;
	}
	//binary operation
	{
		std::cout<<"binary itr,itr,itr,itr,itr,op:"<<std::endl;
		std::vector<int> v0={0,1,2,3};
		std::vector<int> v1={0,2,4,8};
		std::vector<int> v2;
		v2.resize(v0.size());
		for(auto a:v0){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		for(auto a:v1){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		std::transform(v0.begin(),v0.end(),v1.begin(),v2.begin(),[](int a,int b){
				return a+b;
		});
		for(auto a:v2){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
	}
	//different types of containers
	{
		std::cout<<"different containers:"<<std::endl;
		std::map<std::string,int>  m={
			std::make_pair("A",0),
			std::make_pair("B",2),
			std::make_pair("C",4),
			std::make_pair("D",8)
		};
		std::vector<int> v;
		v.resize(m.size());
		std::transform(m.begin(),m.end(),v.begin(),[](auto a){return a.second;});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		v.clear();
		std::transform(m.begin(),m.end(),std::back_inserter(v),[](auto a){return a.second;});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;

	}
	//class member function test [lambda]
	{
		std::vector<A> a={
			A(0),
			A(1),
			A(2),
			A(3)
		};
		std::vector<int> b;
		std::transform(
			std::begin(a),
			std::end(a),
			std::back_inserter(b),
			//A::get_ma//will not compile
			/*
			 * ./src/a.cpp:103:7: error: call to non-static member function without an object argument
			 *                         A::get_ma
			 *                                                 ~~~^~~~~~
			 *                                                 1 error generated.
			 *
			 */
			[](auto c){
				return c.get_ma();
			}
		);
		std::cout<<"Class member lambdas:"<<std::endl;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	//class member function test [std::function]
	{
		std::vector<A> a={
			A(0),
			A(1),
			A(2),
			A(3)
		};
		std::vector<int> b;
		std::transform(
			std::begin(a),
			std::end(a),
			std::back_inserter(b),
			std::function<int(A const&)>(&A::get_ma)
		);
		std::cout<<"Class member std::function:"<<std::endl;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	//class member function test [std::mem_fn]
	{
		std::vector<A> a={
			A(0),
			A(1),
			A(2),
			A(3)
		};
		std::vector<int> b;
		std::transform(
			std::begin(a),
			std::end(a),
			std::back_inserter(b),
			std::mem_fn(&A::get_ma)
		);
		std::cout<<"Class member std::function:"<<std::endl;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	{
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
	}
	return EXIT_SUCCESS;
}

