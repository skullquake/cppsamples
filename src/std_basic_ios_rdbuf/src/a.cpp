/*
 * Stream objects have an internal stream buffer
 * Buffers may vary for streams of different kinds
 * rdbuf() returns a point to the streams' internal buffer object
 * The returned filebuf object does not necessarily contain everything that is in the file. In almost all cases it will not contain everything.
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
int main(void){
	{
		std::istringstream iss("0123456789abcdef");
		std::ostringstream oss;
		oss<<iss.rdbuf();
		std::cout<<oss.str()<<std::endl;
	}
	{
		std::ofstream ofs("./a.txt");
		if(ofs){
			ofs<<"0123456789abcdef";
			ofs.close();
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{
		std::ifstream ifs("./a.txt");
		if(ifs){
			std::ostringstream oss;
			oss<<ifs.rdbuf();
			std::cout<<oss.str()<<std::endl;
			ifs.close();
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{
		std::ofstream ofs("./b.txt");
		if(ofs){
			std::istringstream iss("0123456789abcdef");
			ofs<<iss.rdbuf();
			ofs.close();
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{
		std::ifstream ifs("./b.txt");
		if(ifs){
			std::ostringstream oss;
			oss<<ifs.rdbuf();
			std::cout<<oss.str()<<std::endl;
			ifs.close();
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
