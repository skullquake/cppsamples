/*
 * std::regex_match checks that the entire string conforms
 * to the specified regular expression pattern
 * compare with std::regex_search
 */
#include<iostream>
#include<regex>
int main(int argc,char** argv){
	auto const rexp=std::regex("(foo|bar) baz");
	std::cout
		<<std::boolalpha
		<<std::regex_match(std::string("foo baz"),rexp)<<std::endl
		<<std::regex_match(std::string("bar baz"),rexp)<<std::endl
		<<std::regex_match(std::string("qux baz"),rexp)<<std::endl
		<<std::regex_match(std::string("lorem foo baz ipsum"),rexp)<<std::endl
		<<std::regex_match(std::string("lorem bar baz ipsum"),rexp)<<std::endl
		<<std::regex_match(std::string("lorem qux baz ipsum"),rexp)<<std::endl
	;
	return 0;
}
