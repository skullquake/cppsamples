#include<iostream>
#include<sstream>
#include<random>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	std::ranlux24_base r24b;
	ss<<r24b;
	for(size_t i=0;i<4;++i)
		std::cout<<r24b()<<std::endl;
	std::cout<<std::endl;
	ss>>r24b;
	r24b.discard(2);
	for(size_t i=0;i<4;++i)
		std::cout<<r24b()<<std::endl;
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}
