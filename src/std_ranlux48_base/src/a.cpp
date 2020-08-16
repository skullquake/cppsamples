#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::ranlux48_base r48b;
	ss<<r48b;
	for(size_t i=0;i<4;++i)
		std::cout<<r48b()<<std::endl;
	std::cout<<std::endl;
	ss>>r48b;
	r48b.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<r48b()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
