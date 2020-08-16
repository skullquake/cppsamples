#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::mt19937 m;
	ss<<m;
	for(size_t i=0;i<4;++i)
		std::cout<<m()<<std::endl;
	std::cout<<std::endl;
	ss>>m;
	m.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<m()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
