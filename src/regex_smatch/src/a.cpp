/*
 * std::smatch is a specialization of std::match_results
 * it is used in std::regex_search and is used to hold
 * specific information on the std::regex_search results
 */
#include<iostream>
#include<regex>
int main(int argc,char** argv){
	auto const rtxt=std::string("foo baz");
	auto const rexp=std::regex("(foo|bar) baz");
	auto sres=std::smatch();
	bool const sfnd=std::regex_search(rtxt,sres,rexp);
	std::cout<<(
		sfnd?(
			 "Found ["
			+std::to_string(sres.prefix().length())
			+"]"
		):(
			"Not found"
		)
	)<<std::endl;
	return 0;
}
