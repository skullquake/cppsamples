#include<iostream>
#define FOO 42
#define BAR "BAZ"
#define QUX "KLUTZ"
#define KLUTZ QUX
#undef QUX
int main(void){
	std::cout<<FOO<<std::endl;
	std::cout<<BAR<<std::endl;
}
