#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::subtract_with_carry_engine<std::uint_fast32_t,24,10,24>swce;
	ss<<swce;
	for(size_t i=0;i<8;++i)
		std::cout<<swce()<<std::endl;
	std::cout<<std::endl;
	ss>>swce;
	swce.discard(2);
	for(size_t i=0;i<8;++i)
		std::cout<<swce()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
