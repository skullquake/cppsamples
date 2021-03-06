#include<iostream>
#include<iomanip>
#include<random>
#include<sstream>
#include<cstdlib>
int main(void){
	/*
	 * std::default_random_engine is implementation defined
	 * other generators include the following
	 * std::linear_congruential_engine
	 * std::linear_congruential_engine
	 * std::mersenne_twister_engine
	 * std::subtract_with_carry_engine
	 * std::discard_block_engine
	 * std::shuffle_order_engine
	 */
	std::default_random_engine dre;
	dre.seed();//reinitializes the internal state of the random-number engine using new seed value with default_seed
	dre.seed(48);//reinitializes the internal state of the random-number engine using new seed value
	std::stringstream ss;
	ss<<dre<<std::endl;//serlializes the internal state of the pseudo-random number engine e as a sequence of decimal numbers seperated by one or more spaces, and inserts it to the stream ost. the fill character and formatting flags of the stream are ignored and unaffected
	std::cout<<std::endl;
	std::cout<<ss.str()<<std::endl;
	for(size_t i=0;i<8;++i)
		std::cout<<dre()<<std::endl;//generates a pseudo-random value. the state of the engine is advanced by one position
	std::cout<<std::endl;
	{
		std::stringstream ss;
		ss<<dre<<std::endl;
		std::cout<<std::endl;
		std::cout<<ss.str()<<std::endl;
	}
	ss>>dre;//restores the internal state of the pseudo-rando mnumber engine e from the serialized representation, which was created by an earlier call to operator<< using a stream with the same imbued locale and the same CharT and Traits. if the input cannot be deserialized, e is left unchanged and failbit is raised on ist
	dre.discard(2);//advances the internal state by z times
	for(size_t i=0;i<4;++i)
		std::cout<<dre()<<std::endl;
	std::cout<<std::endl;
	std::cout<<dre.min()<<std::endl;//returns the minimum value potentially generated by the random-number engine. this value is equal to 1u if incremet is 0u, and is equal to 0u otherwise
	std::cout<<dre.max()<<std::endl;//returns the maximum value potentially generated by the random-number engine. this value is one less than modulus
	{
		std::default_random_engine dre0;
		std::default_random_engine dre1;
		//std::cout<<std::boolalpha<<dre0==dre1<<std::endl;//???
	}
	return EXIT_SUCCESS;
}
