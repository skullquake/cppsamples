#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::shuffle_order_engine<std::minstd_rand0,256>soe;
	ss<<soe;
	for(size_t i=0;i<4;++i)
		std::cout<<soe()<<std::endl;
	std::cout<<std::endl;
	ss>>soe;
	soe.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<soe()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
