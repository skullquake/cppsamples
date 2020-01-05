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
		auto b=[](){};
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
	return 0;
}
