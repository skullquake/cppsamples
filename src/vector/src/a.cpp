#include<vector>
#include<iostream>
int main(int argc,char** argv){
	std::vector<int> a;
	for(int b=0;b<4;b++)
		a.push_back(b);
	for(int b=0;b<a.size();b++)
		std::cout<<a[b]<<std::endl;
	for(auto b:a)
		std::cout<<b<<std::endl;
	for(std::vector<int>::iterator b=a.begin();b!=a.end();++b)
		std::cout<<*b<<std::endl;
	return 0;
}
