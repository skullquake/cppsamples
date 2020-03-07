#include<iostream>
#include<unordered_set>
#include<iterator>
int main(int argc,char** argv){
	std::unordered_set<std::string> a={"a","b","c","d"};
	for(auto b:a){
		std::cout<<b<<" ";
	}
	std::cout<<std::endl;
}

