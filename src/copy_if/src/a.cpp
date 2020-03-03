/*
 * copies elements in range to another range that begins at a specified element
 */
#include<iostream>
#include<vector>
#include<algorithm>
int main(int argc,char** argv){
	std::vector<int> v={0,1,2,3};
	std::vector<int> o;
	std::copy_if(v.begin(),v.end(),std::back_inserter(o),[](int a){return a%2==0;});
	for(auto a:v){
		std::cout<<a<<" ";
	}
	std::cout<<std::endl;
	for(auto a:o){
		std::cout<<a<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
