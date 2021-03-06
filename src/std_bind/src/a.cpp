#include<iostream>
#include<functional>
class C{
	public:
		C(){};
		~C(){};
		void vv(void){
			std::cout<<"C::vv()"<<std::endl;
		}
		void vi(int i){
			std::cout<<"C::vi():"<<i<<std::endl;
		}
	private:
};
void vii(int,int);
int main(void){
	[](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;}(1,2);
	std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},std::placeholders::_1,std::placeholders::_2)(1,2);
	std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},std::placeholders::_2,std::placeholders::_1)(1,2);
	{
		auto b=std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},std::placeholders::_1,std::placeholders::_2);
		b(1,2);
	}
	std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},1,std::placeholders::_1)(2);
	std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},std::placeholders::_1,1)(2);
	std::bind([](int a,int b){std::cout<<"["<<a<<","<<b<<"]"<<std::endl;},1,2)();
	std::bind(vii,1,2)();
	std::bind(vii,std::placeholders::_1,std::placeholders::_2)(1,2);
	std::cout<<std::endl;
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},a);//compare with std::ref(a)
		b();
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},std::ref(a));
		b();
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},std::placeholders::_1);
		b(a);
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},a);//compare with std::ref(a)
		[](decltype(b)&a){
			a();
		}(b);
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},std::ref(a));
		[](decltype(b)&a){
			a();
		}(b);
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		int a=42;
		std::cout<<&a<<":"<<a<<std::endl;
		auto b=std::bind([](decltype(a)&c){
				std::cout<<&c<<":"<<c<<std::endl;
				++c;
		},std::placeholders::_1);
		[](decltype(b)&b,decltype(a)&a){b(a);}(b,a);
		std::cout<<&a<<":"<<a<<std::endl;
		std::cout<<std::endl;
	}
	{
		std::vector<C>v;
		for(size_t i=0;i<8;++i){
			v.push_back(C());
		}
		std::for_each(v.begin(),v.end(),std::bind(&C::vv,std::placeholders::_1));
		std::for_each(v.begin(),v.end(),std::bind(&C::vi,std::placeholders::_1,42));
	}
	return EXIT_SUCCESS;
}
void vii(int a,int b){
	std::cout<<"["<<a<<","<<b<<"]"<<std::endl;
}
