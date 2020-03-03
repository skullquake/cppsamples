/*
 * set
 * std::set is an associative container
 */
#include<iostream>
#include<set>
#include<iterator>
int main(int argc,char** argv){
	std::set <std::string> s;
	// insert elements in random order
	s.insert("a");
	s.insert("b");
	s.insert("a");
	s.insert("b");
	for(auto i=s.begin();i!=s.end();++i){
		std::cout<<'\t'<<*i<<std::endl;;
	}
	std::cout<<s.count("a")<<std::endl;
	std::cout<<s.count("b")<<std::endl;
	s.erase("a");
	for(auto i=s.begin();i!=s.end();++i){
		std::cout<<'\t'<<*i<<std::endl;;
	}
	std::cout<<s.count("a")<<std::endl;
	std::cout<<s.count("b")<<std::endl;
	s.erase(s.begin(),s.end());
	for(auto i=s.begin();i!=s.end();++i){
		std::cout<<'\t'<<*i<<std::endl;;
	}
	std::cout<<s.count("a")<<std::endl;
	std::cout<<s.count("b")<<std::endl;
	return 0;
}

