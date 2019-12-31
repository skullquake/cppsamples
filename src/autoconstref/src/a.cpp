/*
 * auto strips const &
 */
#include<iostream>
const int& a(){
	auto b=std::make_shared<int>();
	*b=8;
	return *b;
}
int main(int argc,char** argv){
	const auto& b=a();//avoid stripping
	std::cout<<b<<std::endl;
	return 0;
}
