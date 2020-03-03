/*
 * std::for_each
 * applies a given function object f to the result of
 * dereferencing every iterator in range [first,last]
 */
#include<iostream>
#include<vector>
void inc(int& a){
	++a;
}
void dec(int& a){
	--a;
}
int main(int argc,char** argv){
	std::vector<int> v={0,1,2,3};
	for(auto a:v){
		std::cout<<a<<" ";
	}
	std::cout<<std::endl;
	{
		std::for_each(v.begin(),v.end(),inc);
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		std::for_each(v.begin(),v.end(),dec);
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
	}
	{
		std::for_each(v.begin(),v.end(),[](int& a){
			a++;
		});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		std::for_each(v.begin(),v.end(),[](int& a){
			a--;
		});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;

	}
	return 0;
}
