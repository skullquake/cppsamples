/*
 * generate takes a range and a function/function object that is callable
 * with no parameter that returns a value, and this value will be assigned
 * to the element in the range
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
int main(int argc,char** argv){
	std::vector<int> a;
	a.resize(8);
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<> d(1,32);
	std::generate(a.begin(),a.end(),[&](){
		return d(g);
	});
	for(auto b:a){
		std::cout<<b<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
