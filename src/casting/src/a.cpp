/*
 * variables can be converted to other types by casting them
 */
#include<iostream>
int main(int argc,char** argv){
	float myFloat=3.14f;
	int i1=(int)myFloat;
	int i2=int(myFloat);
	int i3=static_cast<int>(myFloat);
	std::cout<<myFloat<<std::endl;
	std::cout<<i1<<std::endl;
	std::cout<<i2<<std::endl;
	std::cout<<i3<<std::endl;
	return 0;
}
