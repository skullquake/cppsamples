#include<iostream>
#include<json/json.h>
int main(int argc,char** argv){
	Json::Value a;
	for(int i=0;i<4096;i++){
		a[std::to_string(i)]=i;
	}
	std::cout<<a<<std::endl;
	return 0;
}
