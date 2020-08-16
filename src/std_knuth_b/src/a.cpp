#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::knuth_b kb;
	ss<<kb;
	for(size_t i=0;i<4;++i)
		std::cout<<kb()<<std::endl;
	std::cout<<std::endl;
	ss>>kb;
	kb.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<kb()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
