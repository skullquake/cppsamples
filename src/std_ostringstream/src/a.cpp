#include<iostream>
#include<sstream>
#include<cstdlib>
int main(void){
	{
		std::ostringstream oss;
		oss<<"0123456789abcdef";
		std::cout<<oss.str()<<std::endl;
	}
	{//initialize buffer
		std::ostringstream oss("01234567");
		oss.seekp(0,std::ios_base::end);
		oss<<"89abcdef";
		std::cout<<oss.str()<<std::endl;
	}
	{//open mode
		std::ostringstream oss("01234567",std::ios::out|std::ios::ate);
		oss<<"89abcdef";
		std::cout<<oss.str()<<std::endl;
	}
	return EXIT_SUCCESS;
}
