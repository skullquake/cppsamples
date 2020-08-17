#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::default_random_engine dre;
	ss<<dre;
	std::uniform_int_distribution/*<int>*/ uid(0,10);
	for(size_t i=0;i<4;++i)
		std::cout<<uid(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<uid(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
