#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::default_random_engine dre;
	std::binomial_distribution bd(0,10);
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<bd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<bd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
