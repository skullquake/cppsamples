#include<iostream>
#include<sstream>
#include<cstdlib>
#define BUFSZ 4
int main(void){
	std::istringstream iss(R"(0123
4567
89ab
cdef
0123456789abcdef)");
	char buf[BUFSZ+1];
	size_t chnksz;
	while((chnksz=iss.readsome(buf,BUFSZ))>0){
		buf[chnksz]='\0';
		std::cout<<buf;
	}std::cout<<std::endl;
	return EXIT_SUCCESS;
}
