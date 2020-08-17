#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::default_random_engine dre;
	std::student_t_distribution std(1.0);//produces random floating-point values x, distributed according to the probability density function
	std::stringstream ss;
	ss<<dre;
	for(size_t i=0;i<4;++i)
		std::cout<<std(dre)<<std::endl;
	std::cout<<std::endl;
	ss>>dre;
	for(size_t i=0;i<4;++i)
		std::cout<<std(dre)<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
