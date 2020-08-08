#include<iostream>
#include<sstream>
#include<cstdlib>
#define BUFSZ 81
int main(void){
	{
		std::istringstream iss(R"(0
12
234
3567)");
		char buf[BUFSZ];
		while(!iss.getline(buf,BUFSZ).eof()){
			std::cout<<buf<<std::endl;;
		}std::cout<<std::endl;
	}
	{
		std::istringstream iss(R"(0
1,2
2,3,4
3,5,6,7)");
		char buf[BUFSZ];
		while(!iss.getline(buf,BUFSZ,'\n').eof()){
			std::cout<<buf<<std::endl;;
		}std::cout<<std::endl;
	}

	{
		std::istringstream iss(R"(0
1,2
2,3,4
3,5,6,7)");
		char buf[BUFSZ];
		while(!iss.getline(buf,BUFSZ,',').eof()){
			std::cout<<buf<<std::endl;;
		}std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
