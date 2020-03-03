#include<iostream>
int main(int argc,char** argv){
	std::string data="Lorem Ipusm";
	std::cout<<data<<std::endl;
	std::transform(data.begin(),data.end(),data.begin(),::tolower);
	std::cout<<data<<std::endl;
	std::transform(data.begin(),data.end(),data.begin(),::toupper);
	std::cout<<data<<std::endl;
	return 0;
}
