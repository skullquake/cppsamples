#include<iostream>
#include<sstream>
#include<cstdlib>
int main(void){
	{
		std::istringstream iss("0123456789abcdef");
		std::string s;
		iss>>s;
		std::cout<<s<<std::endl;
	}
	{
		int a;
		std::istringstream("42")>>a;
		std::cout<<a<<std::endl;
	}
	{
		std::istringstream iss("0123456789abcdef");
		std::string s;
		iss>>s;
		std::cout<<s<<std::endl;
		iss.str("fedcba9876543210");//??? replace contents???
		iss>>s;
		std::cout<<s<<std::endl;
	}
	{//split string into components by whitespace
		std::string a,b,c,d;
		if(std::istringstream("lorem ipsum sit consecutar")>>a>>b>>c>>d){
			std::cout<<a<<std::endl;
			std::cout<<b<<std::endl;
			std::cout<<c<<std::endl;
			std::cout<<d<<std::endl;
		}else{
			std::cerr<<"failed to parse components"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
