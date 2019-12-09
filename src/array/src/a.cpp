#include<iostream>
#include<array>
int main(int argc,char** argv){
	{
		std::array<int,4> a;
		for(int b=0;b<a.size();b++){
			a[b]=b;
		}
		for(int b=0;b<a.size();b++){
			std::cout<<a[b]<<std::endl;
		}
		std::cout<<"----------------------------------------"<<std::endl;
	}
	{
		std::array<int,4> a={0,1,2,3};
		for(int b=0;b<a.size();b++){
			std::cout<<a[b]<<std::endl;
		}
		std::cout<<"----------------------------------------"<<std::endl;
	}
	{
		std::array<int,4> a={0,1,2,3};
		for(int b=0;b<a.size();b++){
			std::cout<<a[b]<<std::endl;
		}
		std::cout<<"----------------------------------------"<<std::endl;
		std::cout<<std::get<0>(a)<<std::endl;
		std::cout<<std::get<1>(a)<<std::endl;
		std::cout<<std::get<2>(a)<<std::endl;
		std::cout<<std::get<3>(a)<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
		std::cout<<a.front()<<std::endl;
		std::cout<<a.back()<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
	}

	return 0;
}
