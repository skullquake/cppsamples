#include<iostream>
int main(int argc,char** argv){
	std::string s;
	s="foobar";
	s.replace("foo","qwer");
	std::cout<<s<<std::endl;
	return 0;
}
