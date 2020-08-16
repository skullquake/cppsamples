/*
 * cppreference/reference/en/cpp/io/ios_base.html
 * std::ios_base::app		seek to end of stream before each write
 * std::ios_base::binary	open in binary mode
 * std::ios_base::in		open for reading
 * std::ios_base::out		open for writing
 * std::ios_base::trunc		discard the contents of the stream when opening
 * std::ios_base::ate		seek to the end of stream immediately after open
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
int main(void){
	{
		std::ios_base::openmode flags=
			   std::ios_base::app
			  |std::ios_base::binary
			//|std::ios_base::in
			//|std::ios_base::out
			//|std::ios_base::trunc
			//|std::ios_base::ate
		;
		std::ofstream ofs("./a.txt",flags);
	}
	return EXIT_SUCCESS;
}
