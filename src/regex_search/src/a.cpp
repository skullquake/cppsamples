/*
 * std::regex_search checks if parts of the string conforms to the specified
 * regular expression
 * compare with std::regex_match
 */
#include<iostream>
#include<regex>
int main(int argc,char** argv){
	auto const rexp=std::regex("(foo|bar) baz");
	std::cout
		<<std::boolalpha
		<<std::regex_search(std::string("lorem foo baz ipsum"),rexp)<<std::endl
		<<std::regex_search(std::string("lorem bar baz ipsum"),rexp)<<std::endl
		<<std::regex_search(std::string("lorem qux baz ipsum"),rexp)<<std::endl
	;
	return 0;
}
