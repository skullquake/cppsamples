#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::mt19937_64 mt64;
	ss<<mt64;
	for(size_t i=0;i<4;++i)
		std::cout<<mt64()<<std::endl;
	std::cout<<std::endl;
	ss>>mt64;
	mt64.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<mt64()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
