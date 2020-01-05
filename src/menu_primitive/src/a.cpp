/*
 * menu sample
 *  primitive example
 */
#include<iostream>
void option1(){
	std::cout<<"option1()"<<std::endl;
}
void option2(){
	std::cout<<"option2()"<<std::endl;
}

int main(int argc,char** argv){
	std::string input("");
	int option(-1);
	bool done(false);
	while(!done){
		std::cout<<R"(----------------------------------------
Menu
----------------------------------------
0. Quit
1. Option 1
2. Option 2
----------------------------------------
)";
		std::cin>>input;
		try{
			option=std::stoi(input);
			switch(option){
				case 0:
					done=true;
					break;
				case 1:
					option1();
					break;
				case 2:
					option2();
					break;
				default:
					std::cerr<<"Invalid input"<<std::endl;
					break;
			}
		}catch(std::exception e){
			std::cerr<<e.what()<<std::endl;
		}
	}
	return 0;
}
