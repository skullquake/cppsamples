#include<iostream>
#include<algorithm>
#include<regex>
#include<iterator>
#include<cstdlib>
int main(void){
	{//for loop
		std::string s("a, bc, def, ghij");
		std::regex r("[[:space:]]*[,;.][[:space:]]*");
		for(std::sregex_token_iterator pos(s.cbegin(),s.cend(),r,{-1});pos!=std::sregex_token_iterator();++pos){
			std::cout<<*pos<<std::endl;
		}
	}
	{//algorithm
		std::string s("a, bc, def, ghij");
		std::regex r("[[:space:]]*[,;.][[:space:]]*");
		std::sregex_token_iterator beg(s.cbegin(),s.cend(),r,{-1});
		std::sregex_token_iterator end;
		std::for_each(beg,end,[](const auto&i){
			std::cout<<i<<std::endl;
		});
	}
	return EXIT_SUCCESS;
}
