/*
 * -std=c++17 introduces structured bindings
 *  this allows you to declare multiple variables that are initizlied
 *  from an array, struct, pair, or tuple
 *  you have to use the auto keyword for structured bindings
 */
#include<iostream>
#include<array>
int main(int argc,char** argv){
	std::array<int,3> a={1,2,3};//std::array
	auto [b,c,d]=a;//structured binding
	std::cout<<b<<std::endl;//verify
	std::cout<<c<<std::endl;//verify
	std::cout<<d<<std::endl;//verify
	return 0;
}
