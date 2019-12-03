#include<iostream>
int main(int argc,char** argv){
	float a=0.5;
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	std::cout<<reinterpret_cast<unsigned char*>(&a);
	return 0;
}
