#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::poisson_distribution pd(1.0);
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<pd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	for(size_t i=0;i<4;++i)
		std::cout<<pd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
