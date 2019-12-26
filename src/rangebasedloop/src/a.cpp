/*
 * ranged-based for loops allows easy iteration over elements of a container
 * this type of loops works for c-style arrays, initializer lists, and any
 * type that has begin() and end() methods returning iterattors, like
 * std::array, std::vector, and all other standard library containers
 */
#include<iostream>
#include<array>
int main(int argc,char** argv){
	std::array<int,4> a={0,1,2,3};
	for(int b:a){
		std::cout<<b<<std::endl;
	}
	return 0;
}
