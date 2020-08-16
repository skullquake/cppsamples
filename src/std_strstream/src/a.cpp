#include<iostream>
#include<sstream>
#include<strstream>
#include<cstdlib>
int main(void){
	{//std::istringstream
		std::istringstream iss("0123456789abcdef");
		std::string s;
		iss>>s;
		std::cout<<s<<std::endl;
	}
	{//std::ostringstream
		std::ostringstream oss;
		oss<<"0123456789abcdef";
		std::cout<<oss.str()<<std::endl;
		oss.str("____");
		std::cout<<oss.str()<<std::endl;
	}
	{//strstream
		std::strstream ss;
		ss<<"lorem";
		std::cout<<ss.str()<<std::endl;
		std::string s;
		ss>>s;
		std::cout<<s<<std::endl;
	}
	return EXIT_SUCCESS;
}
