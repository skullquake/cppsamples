#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::extreme_value_distribution evd(0.0);//produces random numbers according to the extreme value distribution (it is also known as Gumbel Type I, log-Weibull, Fisher-Tippet Type I)
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<evd(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	dre.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<evd(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
