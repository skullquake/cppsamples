#include<iostream>
#include<cstdlib>
int main(void){
	char a[]="01234567\n";
	std::cout.write(a,sizeof(a)/sizeof(*a));
	return EXIT_SUCCESS;
}
