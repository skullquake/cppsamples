/*
 *
 * Member functions
 * 
 * (constructor)             constructs a new ostreambuf_iterator
 *                           (public member function)
 * (destructor)              destructs an ostreambuf_iterator
 * (implicitly declared)     (public member function)
 * operator=                 writes a character to the associated output sequence
 *                           (public member function)
 * operator*                 no-op
 *                           (public member function)
 * operator++operator++(int) no-op
 *                           (public member function)
 * failed                    tests if output failed
 *                           (public member function)
 */

#include<iostream>
#include<iterator>
#include<sstream>
#include<algorithm>
#include<cstdlib>
int main(void){
	{//ostreambuf_iterator(ostream_type&stream)
		std::string s="01234567890abcdef";
		std::copy(s.cbegin(),s.cend(),std::ostreambuf_iterator<char>(std::cout));std::cout<<std::endl;
	}
	{//ostreambuf_iterator(ostream_type&stream)
		std::ostreambuf_iterator<char>osi(std::cout);
		for(char i='a';i<='z'&&!osi.failed();++i)osi=i;
		*osi='\n';
	}
	{//ostreambuf_iterator(ostream_type&stream)
		std::ostringstream oss;
		std::ostreambuf_iterator<char>osi(oss);
		for(char i='a';i<='z'&&!osi.failed();++i)osi=i;
		std::cout<<oss.str()<<std::endl;
	}
	{//ostreambuf_iterator(streambuf_type*buffer)
		std::ostringstream oss;
		std::ostreambuf_iterator<char>osi(oss.rdbuf());
		for(char i='a';i<='z'&&!osi.failed();++i)osi=i;
		std::cout<<oss.str()<<std::endl;
	}
	return EXIT_SUCCESS;
}
