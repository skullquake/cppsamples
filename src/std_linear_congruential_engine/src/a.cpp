#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::linear_congruential_engine<std::uint_fast32_t,16807,0,2147483647> lce;//std::linear_congruential_engine is a random number engine based on Linear congruential generator (LCG). a lcg has a state that consists of a single integer
	ss<<lce;
	for(size_t i=0;i<4;++i){
		std::cout<<lce()<<std::endl;
	}
	for(size_t i=0;i<4;++i){
		std::cout<<lce()<<std::endl;
	}
	ss>>lce;
	lce.discard(2);
	for(size_t i=0;i<4;++i){
		std::cout<<lce()<<std::endl;
	}
	return EXIT_SUCCESS;
}
