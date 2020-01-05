#include<iostream>
#include<chrono>
#define DEBUG
void log(const std::string& msg){
#ifdef DEBUG
	std::cout
		<<std::chrono::duration_cast
		<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch()
		).count()
		<<":log:"
		<<msg
		<<std::endl
	;
#endif
}
int main(int argc,char** argv){
	log("main()");
	return 0;
}
