/*
 * std::all_of from algorithm operates on a whole range of elements and performing
 * some check and if all checks evaluates to true it returns, otherwise it returns false
 */
#include<iostream>
#include<vector>
#include<algorithm>
int main(int argc,char** argv){
	std::vector<int> a={0,2,4,6};
	std::vector<int> b={0,2,4,5};
	std::cout<<"A:"<<(std::all_of(a.begin(),a.end(),[](int c){
		return c%2==0;}
	)?"all even":"not all even")<<std::endl;
	std::cout<<"B:"<<(std::all_of(b.begin(),b.end(),[](int c){
		return c%2==0;}
	)?"all even":"not all even")<<std::endl;
	return 0;
}
