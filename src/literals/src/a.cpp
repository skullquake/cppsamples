/*
 * literals are used to write number or strings in your code
 */
#include<iostream>
int main(int argc,char** argv){
	std::cout<<"Hello world"<<std::endl;
	std::cout<<123<<std::endl;
	std::cout<<0123<<std::endl;
	std::cout<<0x123<<std::endl;
	std::cout<<0b111<<std::endl;
	std::cout<<1.23f<<std::endl;
	std::cout<<1.23<<std::endl;
	std::cout<<'a'<<std::endl;
	std::cout<<"123"<<std::endl;
	/*
	 * digits seperation
	 */
	/* ???
	std::cout(123'123)<<std::endl;
	std::cout(123'123f)<<std::endl;
	*/
	return 0;
}
