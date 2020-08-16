#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::minstd_rand mr;
	ss<<mr;
	for(size_t i=0;i<4;++i)
		std::cout<<mr()<<std::endl;
	std::cout<<std::endl;
	ss>>mr;
	mr.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<mr()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
