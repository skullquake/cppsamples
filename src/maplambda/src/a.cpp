#include<iostream>
#include<map>
#include<functional>
int main(int argc,char** argv){
	bool done=false;
	std::map<std::string,std::function<void(void)>> a={
		std::pair<std::string,std::function<void(void)>>(
			"0",[=](){
				std::cout<<"Option 0"<<std::endl;
			}
		),
		std::pair<std::string,std::function<void(void)>>(
			"1",[=](){
				std::cout<<"Option 1"<<std::endl;
			}
		),
		std::pair<std::string,std::function<void(void)>>(
			"2",[&](){
				std::cout<<"Option 2"<<std::endl;
			}
		),
		std::pair<std::string,std::function<void(void)>>(
			"q",[&](){
				std::cout<<"Quitting"<<std::endl;
			}
			done=true;
		)

	};
	while(!done){
		int idx=0;
		for(auto b:a){
			std::cout
				<<idx++
				<<". "
				<<b.first
				<<std::endl
			;
		}
		std::string selection;
		std::cin>>selection;
		if(a.find(selection)!=a.end()){
			a[selection]();
		}else{
			std::cerr<<"Invalid option"<<std::endl;
		}
	}
	return 0;
}
