/*
 * call lambda on each char
 */
#include<iostream>
#include<algorithm>
#include<algorithm>
int main(int argc,char** argv){
	std::string data="Lorem ipsum sit consecutar dolor amet";
	std::cout<<data<<std::endl;
	char prv=data[0];
	std::for_each(data.begin(),data.end(),[&](char&c){
			if(c!=' '&&prv==' '){
				std::cout<<char(::toupper(c));
			}else{
				std::cout<<c;
			}
			prv=c;
	});
	std::cout<<std::endl;
	std::cout<<data<<std::endl;
	std::for_each(data.begin(),data.end(),[&](char&c){
			if(c!=' '&&prv==' '){
				c=char(::toupper(c));
			}else{
				//c=c;
			}
			prv=c;
	});
	std::cout<<data<<std::endl;
	std::transform(data.begin(),data.end(),data.begin(),[&](char&c){
			char ret;
			if(c!=' '&&prv==' '){
				ret=char(::tolower(c));
			}else{
				ret=c;
			}
			prv=c;
			return ret;
	});
	std::cout<<data<<std::endl;
	return 0;
}
