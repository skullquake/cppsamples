#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::mersenne_twister_engine<std::uint_fast32_t,32,624,397,31,
		0x9908b0df,11,
		0xffffffff,7,
		0x9d2c5680,15,
		0xefc60000,18,
		1812433253
	>mte;
	ss<<mte;
	for(size_t i;i<8;++i)
		std::cout<<mte()<<std::endl;
	std::cout<<std::endl;
	ss>>mte;
	mte.discard(2);
	for(size_t i;i<8;++i)
		std::cout<<mte()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
