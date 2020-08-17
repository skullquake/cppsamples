#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::fisher_f_distribution ffd(1.0);//produces random numbers accordin to the f-distribution
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<ffd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<ffd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
