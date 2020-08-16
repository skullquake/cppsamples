#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::discard_block_engine<std::ranlux24_base,223,23>dbe;
	ss<<dbe;
	for(size_t i=0;i<4;++i)
		std::cout<<dbe()<<std::endl;
	std::cout<<std::endl;
	ss>>dbe;
	dbe.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<dbe()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
