#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
int main(void){
	{
		std::ofstream("./a.txt")<<"0123456789abcdef";
	}
	{//std::ios::pos_type
		std::ifstream ifs("./a.txt");
		if(ifs){
			char c;
			while(ifs.get(c)){
				//std::basic_istream::tellg
				std::ios::pos_type pos=ifs.tellg();
				std::cout<<std::setw(4)<<pos<<": "<<c<<std::endl;
			}
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::streampos
		std::ifstream ifs("./a.txt");
		if(ifs){
			char c;
			while(ifs.get(c)){
				//std::basic_istream::tellg
				std::streampos pos=ifs.tellg();
				std::cout<<std::setw(4)<<pos<<": "<<c<<std::endl;
			}
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::basic_istream::seekg
		std::ifstream ifs("./a.txt");
		if(ifs){
			std::streampos pos=ifs.tellg();
			std::string s;
			ifs>>s;
			std::cout<<s<<std::endl;
			ifs.seekg(pos);
			ifs>>s;
			std::cout<<s<<std::endl;
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::ios_base::seekdir
		std::ifstream ifs("./a.txt");
		if(ifs){
			ifs.seekg(0,std::ios::end);
			auto pos=ifs.tellg();
			std::cout<<pos<<std::endl;
			ifs.seekg(0,std::ios::beg);
			pos=ifs.tellg();
			std::cout<<pos<<std::endl;
			ifs.seekg(-1,std::ios::end);
			pos=ifs.tellg();
			std::cout<<pos<<std::endl;
			ifs.seekg(1,std::ios::beg);
			pos=ifs.tellg();
			std::cout<<pos<<std::endl;
			//todo: std::ios::cur
		}else{
			std::cerr<<"failed to open file"<<std::endl;
		}
	}
	{//std::ostringstream seek
		std::ostringstream oss;
		oss<<"01234567890bcdef";
		std::cout<<oss.str()<<std::endl;
		oss.seekp(0,std::ios::beg);
		oss<<std::string(8,'_');
		std::cout<<oss.str()<<std::endl;
		oss.seekp(0,std::ios::beg);
		oss<<"012345678";
		std::cout<<oss.str()<<std::endl;
		oss.seekp(-8,std::ios::end);
		oss<<std::string(8,'_');
		std::cout<<oss.str()<<std::endl;
	}
	return EXIT_SUCCESS;
}
