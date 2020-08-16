#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstdlib>
int main(int argc,char** argv){
	{
		std::istringstream iss("0123456789abcdef");
		std::istreambuf_iterator<char>pos(iss);
		std::istreambuf_iterator<char>end;
		while(pos!=end){
			std::cout<<(*pos++);
		}std::cout<<std::endl;
	}
	{
		std::istringstream iss("0123456789abcdef");
		std::ostringstream oss;
		std::istreambuf_iterator<char>inpos(iss);
		std::istreambuf_iterator<char>inend;
		std::ostreambuf_iterator<char>outpos(oss);
		while(inpos!=inend){
			outpos=*inpos++;
		}
		std::cout<<oss.str()<<std::endl;
	}
	{
		std::istringstream iss("0123456789abcdef");
		std::istreambuf_iterator<char>pos(iss);
		std::istreambuf_iterator<char>end();
		std::for_each(pos,end,[](auto&i){});
	}
	return 0;
}
