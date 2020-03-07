/*
 * std::copy takes two iterators denoting the source range
 * and a third denoting the target range
 * it performs a copy from the source to the target
 */
#include<iostream>
#include<algorithm>
#include<vector>
int main(int argc,char** argv){
	std::vector<int> a={0,1,2,3,4};
	std::vector<int> b;
	std::copy(std::begin(a),std::end(a),std::back_inserter(b));
	for(auto c:a){
		std::cout<<c<<" ";
	}
	std::cout<<std::endl;
	for(auto c:b){
		std::cout<<c<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
