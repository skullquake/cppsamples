#include<iostream>
#define PRINT(VAL)(std::cout<<VAL<<std::endl)
#define MAX(A,B)(A>B?A:B)
#define MIN(A,B)(A<B?A:B)
int main(void){
	PRINT(42);
	PRINT(MAX(4,2));PRINT(MIN(4,2));
	PRINT(MAX(2,4));PRINT(MIN(2,4));
	
}
