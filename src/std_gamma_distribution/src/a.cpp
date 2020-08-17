#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::gamma_distribution gd;//produces random positive floating-point values x, distributed according to the gamma density function
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<gd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<gd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
