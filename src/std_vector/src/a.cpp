/*
 * std::vector is a non-fixed-size container that can be used to store information
 * vector replaces the concept of c-style arrays
 * it is safer and more flexible
 * you dont have to worry about memory management, it automatically allocates enough 
 * memory to hold its elements
 * elements can be added and removed at run time
 * it is generic, and contain any type of object you want
 * the type is specified in the angled brackets
 */
#include<vector>
#include<iostream>
int main(int argc,char** argv){
	std::vector<int> a;
	for(int b=0;b<4;b++)
		a.push_back(b);
	for(int b=0;b<a.size();b++)
		std::cout<<a[b]<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b:a)
		std::cout<<b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::vector<int>::iterator b=a.begin();b!=a.end();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.begin();b!=a.end();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::vector<int>::const_iterator b=a.cbegin();b!=a.cend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.cbegin();b!=a.cend();++b)
		std::cout<<*b<<std::endl;

	std::cout<<"----------------------------------------"<<std::endl;
	for(std::vector<int>::reverse_iterator b=a.rbegin();b!=a.rend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.crbegin();b!=a.crend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(std::vector<int>::const_reverse_iterator b=a.crbegin();b!=a.crend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	for(auto b=a.rbegin();b!=a.rend();++b)
		std::cout<<*b<<std::endl;
	std::cout<<"----------------------------------------"<<std::endl;
	return 0;
}
