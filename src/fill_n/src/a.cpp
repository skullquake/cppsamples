/*
 * assigns the given value to the first n to the elements in range [first,last)
 * first,last: range of elements to modify
 * value: value to be assigned
 */
#include<iostream>
#include<vector>
#include<algorithm>
int main(int argc,char** argv){
	std::vector<int> a;
	a.resize(8);
	std::fill(a.begin(),a.end(),0);
	std::fill_n(a.begin(),a.size()/2,1);
	for(auto b:a){
		std::cout<<b<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
