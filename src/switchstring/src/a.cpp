#include<iostream>
#include<map>
#include<functional>
//--------------------------------------------------------------------------------
/*
 * possible issue: hash collisions
 */
uint64_t constexpr mix(char m,uint64_t s){
	return ((s<<7)+~(s>>3))+~m;
}
uint64_t constexpr hash(const char *m){
	return (*m)?mix(*m,hash(m+1)):0;
}
void test0(){
	std::string in;
	std::cin>>in;
	switch(hash(in.c_str())){
		case hash("foo"):
			std::cout<<"Option 0"<<std::endl;
			break;
		case hash("bar"):
			std::cout<<"Option 1"<<std::endl;
			break;
		case hash(""):
			std::cout<<"No input"<<std::endl;
			break;
		deafult:
			std::cout<<"Invalid option"<<std::endl;
			break;
	}

}
//--------------------------------------------------------------------------------
static enum Opt{
	foo,
	bar,
	baz,
	qux
};
void test1(){
	static std::map<std::string,Opt> opts={
		std::pair<std::string,Opt>("foo",foo),
		std::pair<std::string,Opt>("bar",bar),
		std::pair<std::string,Opt>("baz",baz),
		std::pair<std::string,Opt>("qux",qux)
	};
	std::string in;
	std::cin>>in;
	if(opts.find(in)!=opts.end()){
		switch(opts[in]){

			case foo:
				std::cout<<"option foo"<<std::endl;
				break;
			case bar:
				std::cout<<"option bar"<<std::endl;
				break;
			case baz:
				std::cout<<"option baz"<<std::endl;
				break;
			case qux:
				std::cout<<"option qux"<<std::endl;
				break;
			default:
				std::cout<<"invalid option"<<std::endl;
				break;
		}
	}else{
		std::cout<<"invalid option"<<std::endl;
	}
}
//--------------------------------------------------------------------------------
std::map<std::string,Opt> StrOpt={
	{"foo",Opt::foo},
	{"bar",Opt::bar},
	{"baz",Opt::baz},
	{"qux",Opt::qux}
};
std::map<Opt,std::string> OptStr={
	{Opt::foo,"foo"},
	{Opt::bar,"bar"},
	{Opt::baz,"baz"},
	{Opt::qux,"qux"}
};
void test2(){
	static std::map<std::string,Opt> opts={
		std::pair<std::string,Opt>("foo",foo),
		std::pair<std::string,Opt>("bar",bar),
		std::pair<std::string,Opt>("baz",baz),
		std::pair<std::string,Opt>("qux",qux)
	};
	std::string in;
	std::cin>>in;
	Opt opt=StrOpt[in];
	if(opts.find(in)!=opts.end()){
		switch(opt){
			case Opt::foo:
				std::cout<<"option foo"<<std::endl;
				break;
			case Opt::bar:
				std::cout<<"option bar"<<std::endl;
				break;
			case Opt::baz:
				std::cout<<"option baz"<<std::endl;
				break;
			case Opt::qux:
				std::cout<<"option qux"<<std::endl;
				break;
			default:
				std::cout<<"invalid option"<<std::endl;
				break;
		}
	}else{
		std::cout<<"invalid option"<<std::endl;
	}
}
//--------------------------------------------------------------------------------
int main(int argc,char** argv){
	//test0();
	//test1();
	test2();
	return 0;
}
