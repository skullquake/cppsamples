/*
 * syntax:
 * switch(<initializer>;<expression>{<body>}
 */

#include<iostream>
int main(int argc,char** argv){
	//no initializer
	switch(0){
		case 0:
			std::cout<<"0"<<std::endl;
			break;
		case 1:
			std::cout<<"1"<<std::endl;
			break;
		default:
			std::cout<<"invalid"<<std::endl;
			break;
	};
	//initializer
	switch(int a=0;a){
		case 0:
			std::cout<<"0"<<std::endl;
			break;
		case 1:
			std::cout<<"1"<<std::endl;
			break;
		default:
			std::cout<<"invalid"<<std::endl;
			break;
	};

	return 0;
}
