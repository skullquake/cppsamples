#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::stringstream ss;
	ss<<dre;
	std::negative_binomial_distribution nbd(0,10);
	for(size_t i=0;i<4;++i)
		std::cout<<nbd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	for(size_t i=0;i<4;++i)
		std::cout<<nbd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
