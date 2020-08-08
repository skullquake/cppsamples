#include<iostream>
#include<sstream>
#include<cstdlib>
int main(void){
	{
		std::istringstream iss(R"(0
12
234
3567)");
		char c;
		while((c=iss.get())!=EOF){
			std::cout<<c<<'.';
		}std::cout<<std::endl;
	}
	{
		std::istringstream iss(R"(0
12
234
3567)");
		char c;
		while(!iss.get(c).eof()){
			std::cout<<c<<'.';
		}std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
