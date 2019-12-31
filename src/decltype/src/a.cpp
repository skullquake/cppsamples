/*
 * decltype does not strip const and &
 */
#include<iostream>
const int& a(){
	auto b=std::make_shared<int>();
	*b=8;
	return *b;
}
int main(int argc,char** argv){
	decltype(a()) b=a();
	std::cout<<b<<std::endl;
	return 0;
}
