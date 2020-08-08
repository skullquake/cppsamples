#include<iostream>
#include<sstream>
#include<cstdlib>
#define BUFSZ 5
int main(void){
	{
		std::istringstream iss(R"(0123456789abcdef0123456789abcdef)");
		char buf[BUFSZ+1];
		buf[BUFSZ]='\0';
		while(!iss.read(buf,BUFSZ).eof()){
			std::cout<<'['<<buf<<']'<<'\n';
		}
	}
	return EXIT_SUCCESS;
}
