/*
 * initizlizer lists are defined in the <initizlier_list> header
 * it makes it easy to write functions that can accept a variable number of arguments
 * by sending in an initializer list e.g. {0,1} as an argument
 * the initializer_list class is a template and requires you specify the type
 * of elements in angled brackets
 */
#include<iostream>
#include<initializer_list>
int a(std::initializer_list<int> b){
	int c=0;
	for(int d:b){
		c+=d;
	}
	return c;
}
int main(int argc,char** argv){
	std::cout<<a({})<<std::endl;
	std::cout<<a({0})<<std::endl;
	std::cout<<a({0,1})<<std::endl;
	std::cout<<a({0,1,2})<<std::endl;
	std::cout<<a({0,1,2,3})<<std::endl;
	return 0;
}
