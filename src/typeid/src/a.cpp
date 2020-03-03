/*
 * typeid is a runtime construct and gives
 * information about the runtime type of the value
 * queries information of a type
 * used where dynamic type of polymorphic object must be known and for static type identification
 */

#include<iostream>
#include<vector>
#include<map>
class A{
};
class B:public A{
};
int main(int argc,char** argv){
	size_t a;
	uint8_t b;
	int c;
	char d;
	float e;
	std::vector<int> f;
	std::map<int,int> g;
	A h;
	B i;
	std::cout<<typeid(a).name()<<std::endl;
	std::cout<<typeid(b).name()<<std::endl;
	std::cout<<typeid(c).name()<<std::endl;
	std::cout<<typeid(d).name()<<std::endl;
	std::cout<<typeid(e).name()<<std::endl;
	std::cout<<typeid(f).name()<<std::endl;
	std::cout<<typeid(g).name()<<std::endl;
	std::cout<<typeid(h).name()<<std::endl;
	std::cout<<typeid(i).hash_code()<<":"<<typeid(i).name()<<std::endl;
	return 0;
}
