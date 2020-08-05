#include<iostream>
#include<iomanip>
#include<regex>
#include<iterator>
#include<cstdlib>
int main(void){
	std::string s("A0BA1BA2B___A3B");
	std::regex r("(A.B)");
	for(std::sregex_iterator i(s.begin(),s.end(),r);i!=std::sregex_iterator();++i){
		std::cout<<std::setw(4)<<(i->position())<<':'<<std::setw(4)<<(i->length())<<':'<<std::setw(4)<<(i->str())<<std::setw(s.length())<<(i->prefix())<<std::setw(s.length())<<(i->suffix())<<'\n';
	}
	return EXIT_SUCCESS;
}
