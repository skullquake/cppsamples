#include<iostream>
#include<iomanip>
#include<sstream>
#include<cstdlib>
int main(void){
	std::istringstream iss(R"(0
12
345)");
	int i;
	while(iss>>i){
		std::cout<<std::setw(4)<<iss.gcount()<<':'<<i<<std::endl;//???
	}
	return EXIT_SUCCESS;
}
