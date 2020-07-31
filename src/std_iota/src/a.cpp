/*
 * std::iota fills a range with incremental values obtained with prefix operator++ starting
 * at a specific value
 */
#include<iostream>
#include<vector>
#include<numeric>
int main(int argc,char** argv){
	std::vector<int> a;
	a.resize(8);
	std::iota(a.begin(),a.end(),0);
	for(auto b:a){
		std::cout<<b<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
