#include<iostream>
#include<map>
#include<functional>
int main(int argc,char** argv){
	{
		//map of string and string 
		std::map<std::string,std::string> a;
		for(int i=0;i<8;i++){
			a.insert(
				std::pair<std::string,std::string>(
					"k"+std::to_string(i),
					"v"+std::to_string(i)
				)
			);
		}
		for(auto b:a){
			std::cout
				<<b.first
				<<":"
				<<b.second
				<<std::endl
			;
		}
	}
	{
		//map of string and lambda
		std::map<std::string,std::function<void(void)>> a;
		for(int i=0;i<8;i++){
			a.insert(
				std::pair<
					std::string,
					std::function<void(void)>
				>(
					"k"+std::to_string(i),
					[=](){
						std::cout<<"lambda "<<i<<std::endl;
					}
				)
			);
		}
		for(auto b:a){
			std::cout
				<<b.first
				<<std::endl
			;
			b.second();//call lambda
			std::cout<<"----------------------------------------"<<std::endl;
		}
	}
	{
		//find
		std::map<std::string,std::string> a;
		for(int i=0;i<8;i++){
			a.insert(
				std::pair<std::string,std::string>(
					"k"+std::to_string(i),
					"v"+std::to_string(i)
				)
			);
		}
		if(a.find("k1")!=a.end()){
			std::cout<<"a[\"k1\"]:"<<a["k1"]<<std::endl;
		}else{
			std::cerr<<"a[\"k1\"] not found"<<std::endl;
		}
	}
	{
		//simple menu
		bool done=false;
		std::map<std::string,std::function<void(void)>> a;
		a.insert(
			std::pair<
				std::string,
				std::function<void(void)>
			>(
				"1",
				[=](){
					std::cout<<"Option 1 chosen"<<std::endl;
				}
			)
		);
		a.insert(
			std::pair<
				std::string,
				std::function<void(void)>
			>(
				"2",
				[=](){
					std::cout<<"Option 2 chosen"<<std::endl;
				}
			)
		);
		a.insert(
			std::pair<
				std::string,
				std::function<void(void)>
			>(
				"q",
				[&](){
					std::cout<<"Quitting"<<std::endl;
					done=true;
				}
			)
		);
		std::cout<<"----------------------------------------"<<std::endl;
		std::cout<<"Menu"<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
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
				std::cerr<<"Invalid options"<<std::endl;
			}

		}
	}
	return 0;
}
