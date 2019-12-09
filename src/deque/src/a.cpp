#include<deque>
#include<iostream>
int main(int argc,char** argv){
	std::deque<int> a;
	for(int b=0;b<4;b++)
		a.push_back(b);
	for(int b=0;b<a.size();b++)
		std::cout<<a[b]<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b:a)
		std::cout<<b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::deque<int>::iterator b=a.begin();b!=a.end();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.begin();b!=a.end();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::deque<int>::const_iterator b=a.cbegin();b!=a.cend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.cbegin();b!=a.cend();++b)
		std::cout<<*b<<std::endl;

	std::cout<<"----------------------------------------"<<std::endl;
	for(std::deque<int>::reverse_iterator b=a.rbegin();b!=a.rend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.crbegin();b!=a.crend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::deque<int>::const_reverse_iterator b=a.crbegin();b!=a.crend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.rbegin();b!=a.rend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	return 0;
}
