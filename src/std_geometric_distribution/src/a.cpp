#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::stringstream ss;
	ss<<dre;
	std::geometric_distribution gd(0.5);
	for(size_t i=0;i<16;++i)
		std::cout<<gd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<16;++i)
		std::cout<<gd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
