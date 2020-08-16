/*
 * since c++11 file streams provide rvalue and move semantics
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
int main(void){
	{//std::ofstream - move
		std::ofstream ofs("./a.txt");
		if(ofs){
			[](std::ofstream ofs){
				ofs<<42;
				ofs.close();
			}(std::move(ofs));
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::ifstream - move
		std::ifstream ifs("./a.txt");
		if(ifs){
			[](std::ifstream ifs){
				std::cout<<ifs.rdbuf()<<std::endl;
			}(std::move(ifs));
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::ofstream - rvalue
		[](std::ofstream ofs){
			if(ofs){
				ofs<<42;
				ofs.close();
			}else{
				std::cerr<<"failed to open file"<<std::endl;
			}
		}(std::ofstream("./a.txt"));
	}
	{//std::ifstream - rvalue
		[](std::ifstream ifs){
			if(ifs){
				std::cout<<ifs.rdbuf()<<std::endl;
				ifs.close();
			}else{
				std::cerr<<"failed to open file"<<std::endl;
			}
		}(std::ifstream("./a.txt"));
	}
	{//writing to temporary stream
		try{
			std::ofstream("./c.txt"/*, std::ios::app*/)<<"0123456789abcdef"<<std::endl;
		}catch(...){
			std::cerr<<"failed to write to file"<<std::endl;
		}
	}
	{//reading from temporary streams ???
		std::string s;
		try{
			std::ifstream("./c.txt")>>s;
			std::cout<<s<<std::endl;
		}catch(...){
			std::cerr<<"failed to read from file"<<std::endl;
		}
	}
	{//std::ostringstream - move
		std::ostringstream oss;
		[](std::ostringstream oss){
			oss<<42;
			[](std::ostringstream oss){
				std::cout<<oss.str()<<std::endl;
			}(std::move(oss));
		}(std::move(oss));
	}
	{//std::ostringstream - rvalue
		[](std::ostringstream oss){
			oss<<42;
			[](std::ostringstream oss){
				std::cout<<oss.rdbuf()<<std::endl;
			}(std::move(oss));
		}(std::ostringstream());
	}
	return EXIT_SUCCESS;
}
