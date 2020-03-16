/*
 * the regex_replace() altorighm requires a regular expression
 * and a formatting string that is used to replace mathching substrings
 * this formatting string can reference part of the matched substrings
 * by using the sequences
 */
#include<iostream>
#include<regex>
#include<map>
int main(int argc,char** argv){
	//marc gerboire: professional c++, p 687
	{
		std::string str="<body><h1>Header</h1><p>Some text</p></body>";
		std::regex r("<h1>(.*)</h1><p>(.*)</p>");
		const std::string format("H1=$1 and P=$2");
		std::string result=regex_replace(str,r,format);
		std::cout<<str<<std::endl;
		std::cout<<result<<std::endl;
	}
	//sample replacement
	{
		std::map<std::string,std::string> mtok={
			{"lorem","dorkum"},
			{"ipsum","ipkus"},
			{"sit","greatesthits"},
			{"consecutar","conssecutively"}
		};
		std::string str=R"(lorem ipsum sit consecutar)";
		for(auto tok:mtok){	
			const std::string format(
				regex_replace(
					tok.second,
					std::regex("\\$"),
					"$$$$"
				)//escape regex escape sequences in format
			)
			;
			str=regex_replace(
				str,
				std::regex(tok.first),
				format,
				std::regex_constants::format_default
			);
		}
		std::cout<<str<<std::endl;
	}

	//sample token replacement
	{
		std::map<std::string,std::string> mtok={
			{"TOK0","$1foo"},	// test esc
			{"TOK1","$2bar"},	// test esc
			{"TOK2","$&baz"},	// test esc
			{"TOK3","$`qux"},	// test esc
			{"TOK4","$'klutz"},	// test esc
			{"TOK5","foobar"}	// regular test
		};
		std::string str=
R"(<h1>$TOK0</h1>
<h2>$TOK1</h2>
<h3>$TOK2</h3>
<h4>$TOK3</h4>
<h5>$TOK4</h5>
<h6>$TOK5</h6>
<p>$TOK6</p>
<div>$TOK7</div>)";
		for(auto tok:mtok){	
			const std::string format(
				regex_replace(
					tok.second,
					std::regex("\\$"),
					"$$$$"
				)//escape regex escape sequences in format
			)
			;
			str=regex_replace(
				str,
				std::regex(std::string("\\$")+tok.first),
				format,
				std::regex_constants::format_default
			);
		}
		std::cout<<str<<std::endl;
	}


	return 0;
}
