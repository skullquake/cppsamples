#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::lognormal_distribution lnd(0.0);//generates random numbers according to the Normal (or Gaussian) random number distribution
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<lnd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<lnd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
