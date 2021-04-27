#include<iostream>
int main(void){
	auto a=[](){
		int b;
		return[/*capture*/&b](/*parameter list*/){
			return /*closure*/b++;
		};
	};
	auto b=a();
	std::cout<<b()<<std::endl;
	std::cout<<b()<<std::endl;
	std::cout<<b()<<std::endl;
	std::cout<<b()<<std::endl;
}
