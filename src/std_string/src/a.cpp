#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<algorithm>
#include<iterator>
#include<cstring>
#include<sstream>
int main(int argc,char** argv){
	{
		std::string s("0123456789abcdef");
		std::cout<<s<<std::endl;
		for(size_t i=0;i<s.length();++i){
			std::cout<<s.at(i);
		}std::cout<<std::endl;
		for(size_t i=0;i<s.length();++i){
			std::cout<<s[i];
		}std::cout<<std::endl;
		printf("%s\n",s.data());
		printf("%s\n",s.c_str());
		std::for_each(s.cbegin(),s.cend(),[](const auto&a){std::cout<<a;});std::cout<<std::endl;
		std::cout<<std::boolalpha<<s.empty()<<std::endl;
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		s.clear();
		std::cout<<s<<std::endl;
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		s.reserve(32);
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		s.erase();
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		s.push_back('0');std::cout<<s<<std::endl;
		s.push_back('1');std::cout<<s<<std::endl;
		s.push_back('2');std::cout<<s<<std::endl;
		s.push_back('3');std::cout<<s<<std::endl;
		s.pop_back();std::cout<<s<<std::endl;
		s.pop_back();std::cout<<s<<std::endl;
		s.pop_back();std::cout<<s<<std::endl;
		s.pop_back();std::cout<<s<<std::endl;
		s.append("0123");std::cout<<s<<std::endl;
		s.append("4567");std::cout<<s<<std::endl;
		s.append("89ab");std::cout<<s<<std::endl;
		s.append("cdef");std::cout<<s<<std::endl;
		s.clear();
		s+='0';s+='1';s+='2';s+='3';std::cout<<s<<std::endl;
		std::cout<<s.compare("0123")<<std::endl;
		std::cout<<s.compare("3210")<<std::endl;
		//std::cout<<std::boolalpha<<s.starts_with("01")<<std::endl;//--std=c++20
		//std::cout<<std::boolalpha<<s.starts_with("10")<<std::endl;//--std=c++20
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		std::cout<<"|"<<s<<"|"<<std::endl;
		s.resize(32);
		std::cout<<s.length()<<std::endl;
		std::cout<<s.size()<<std::endl;
		std::cout<<s.capacity()<<std::endl;
		std::cout<<"|"<<s<<"|"<<std::endl;
		std::string s2="XXXX";
		s.swap(s2);
		std::cout<<s<<std::endl;
		std::cout<<s2<<std::endl;
		s.swap(s2);
		std::cout<<s<<std::endl;
		std::cout<<s2<<std::endl;
		std::cout<<s.substr(0,2)<<std::endl;
		std::cout<<s.find("01")<<std::endl;
		std::cout<<s.find("12")<<std::endl;
		std::cout<<s.find("23")<<std::endl;
		std::size_t idx=s.find("10");
		std::cout<<std::boolalpha<<(idx==std::string::npos)<<std::endl;
		s.append("0123");
		std::cout<<s.rfind("01")<<std::endl;
		std::cout<<s.find_first_of("01")<<std::endl;
		std::cout<<s.find_first_not_of("01")<<std::endl;
		std::cout<<s.find_last_of("01")<<std::endl;
		std::cout<<s.find_last_not_of("01")<<std::endl;
		//s.erase("30");
		//std::cout<<s<<std::endl;//--std=c++20
		//getline...
		std::cout<<s<<std::endl;
		s.replace(4,2,"XX");
		std::cout<<s<<std::endl;
		s.replace(4,std::string::npos,"XXXX");
		std::cout<<s<<std::endl;
	}
	{
		std::string a("0123_4567|89ab cdef");
		std::string b("_, |");
		size_t idx=a.find_first_of(b);
		while(idx!=std::string::npos){
			std::cout<<idx<<std::endl;
			idx=a.find_first_of(b,idx+1);
		}
	}
	{
		std::cout<<std::string(1,'x')<<std::endl;;
		std::cout<<std::string(4,'x')<<std::endl;;
	}
	{
		std::string a("0123");
		std::string b="0123";
		std::string c{"0123"};
		std::string d({'x','y'});
		std::string e={'x','y'};
		std::string f("0123",2);
		std::string g("0123",2,32);
		std::string h(a.begin(),a.end());
	}
	{
		char a[32];
		std::sprintf(a,"01\023");
		std::printf("%s\n",a);
		std::string b("32 10");
		b[2]='\0';
		std::cout<<b<<std::endl;
		b.copy(a,5,0);
		std::printf("%s\n",a);
		std::cout<<b.length()<<std::endl;
		for(size_t i=0;i<b.length();++i){
			std::cout<<b[i]<<std::endl;
		}
		std::copy(b.begin(),b.end(),std::ostream_iterator<char>(std::cout,""));
		std::cout<<std::endl;
	}
	{
		std::string s{"0123"};
		char c[32];//{"3210\0"};
		c[0]='\0';
		std::printf("%s\n",c);
		s.copy(c,32,0);
		std::printf("%s\n",c);
	}
	{
		std::string s{"01234567"};
		std::cout<<s<<std::endl;
		s.erase(4);
		std::cout<<s<<std::endl;
		s.append("4567");
		std::cout<<s<<std::endl;
		s.erase(2,4);
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"01234567"};
		std::cout<<s<<std::endl;
		std::cout<<s.substr(4)<<std::endl;
		std::cout<<s.substr(4,2)<<std::endl;
		std::cout<<s.substr(6,2)<<std::endl;
		std::cout<<s.substr(4,std::string::npos)<<std::endl;
		std::cout<<s<<std::endl;
	}
#if 0
	{
		std::string s;
		while(std::getline(std::cin,s)){
			std::cout<<s<<std::endl;
			if(!s.length())break;
		}
	}
#endif
	{
		std::string s{"01234567"};
		std::size_t pos;
		pos=s.find("1");
		if(pos==std::string::npos){
			std::cout<<"Not found"<<std::endl;
		}else{
			std::cout<<"Found: "<<pos<<std::endl;
		}
		pos=s.find("12");
		if(pos==std::string::npos){
			std::cout<<"Not found"<<std::endl;
		}else{
			std::cout<<"Found: "<<pos<<std::endl;
		}
		pos=s.find("21");
		if(pos==std::string::npos){
			std::cout<<"Not found"<<std::endl;
		}else{
			std::cout<<"Found: "<<pos<<std::endl;
		}
	}
	{
		std::string s{"0123456701234567"};
		std::cout<<s.find("01XX",0,2)<<std::endl;;
		std::cout<<s.find("01XX",0,3)<<std::endl;;
		std::cout<<s.find("01XX",1,2)<<std::endl;;
		std::cout<<s.find("01XX",1,3)<<std::endl;;
		std::cout<<s.rfind("01XX")<<std::endl;;
		std::cout<<s.rfind("01XX",15,2)<<std::endl;;
		std::cout<<s.rfind("01XX",15,3)<<std::endl;;
		std::cout<<s.rfind("01XX",7,2)<<std::endl;;
		std::cout<<s.rfind("01XX",7,3)<<std::endl;;
	}
	{
		std::string s{"0123A4567B0123C4567D0123E4567"};
		std::cout<<s.find_first_of("ABCDE")<<std::endl;
		std::cout<<s.find_first_of("ABCDE",5)<<std::endl;
		std::cout<<s.find_first_of("ABCDE",10)<<std::endl;
		std::cout<<s.find_first_of("ABCDE",15)<<std::endl;
	}
	{
		std::string s{"0123A4567B0123C4567D0123E4567"};
		std::cout<<s.find_last_not_of("ABCDE")<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",28)<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",23)<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",18)<<std::endl;
	}
	{
		std::string s{"0123A4567B0123C4567D0123E4567"};
		std::cout<<s.find_first_not_of("ABCDE")<<std::endl;
		std::cout<<s.find_first_not_of("ABCDE",5)<<std::endl;
		std::cout<<s.find_first_not_of("ABCDE",10)<<std::endl;
		std::cout<<s.find_first_not_of("ABCDE",15)<<std::endl;
	}
	{
		std::string s{"0123A4567B0123C4567D0123E4567"};
		std::cout<<s.find_last_not_of("ABCDE")<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",28)<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",23)<<std::endl;
		std::cout<<s.find_last_not_of("ABCDE",18)<<std::endl;
	}
	{
		std::cout<<std::stoi(std::string("  42   "))<<std::endl;
		std::cout<<std::stol(std::string("  42   "))<<std::endl;
		std::cout<<std::stoll(std::string(" 42   "))<<std::endl;
		std::cout<<std::stoul(std::string(" 42   "))<<std::endl;
		std::cout<<std::stoull(std::string("42   "))<<std::endl;
		std::cout<<std::stof(std::string("  42.42"))<<std::endl;
		std::cout<<std::stod(std::string("  42.42"))<<std::endl;
		std::cout<<std::stold(std::string(" 42.42"))<<std::endl;
	}
	{
		std::cout<<std::to_string(42)<<std::endl;
		std::cout<<std::to_string(42.42)<<std::endl;
	}
	{
		std::string s{"0123aBcD"};
		std::for_each(s.begin(),s.end(),[](const auto&a){std::cout<<a;});std::cout<<std::endl;
		std::copy(s.begin(),s.end(),std::ostream_iterator<char>(std::cout,""));std::cout<<std::endl;
		std::transform(s.begin(),s.end(),s.begin(),[](const char&a){return std::tolower(a);});
		std::cout<<s<<std::endl;
		std::transform(s.begin(),s.end(),s.begin(),[](const char&a){return std::toupper(a);});
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		s.insert(s.begin(),'x');
		std::cout<<s<<std::endl;
		s.insert(s.end(),'x');
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.insert(s.begin(),4,'x');
		std::cout<<s<<std::endl;
		s.insert(s.end(),4,'y');
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.insert(s.begin(),{'x','y','z'});
		std::cout<<s<<std::endl;
		s.insert(s.end(),{'z','y','x'});
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.erase(s.begin());
		std::cout<<s<<std::endl;
		s.erase(s.end()-1);
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.replace(s.begin()+1,s.end()-1,"X");
		std::cout<<s<<std::endl;
		s.replace(s.begin()+1,s.end()-1,"12");
		std::cout<<s<<std::endl;
		s.replace(s.begin()+1,s.end()-1,2,'X');
		std::cout<<s<<std::endl;
		s.replace(s.begin()+1,s.end()-1,"12");
		std::cout<<s<<std::endl;
		s.replace(s.begin()+1,s.end()-1,{'x','y','z'});
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123456789abcdef"};
		std::cout<<s.find("4567")<<std::endl;
		std::string n{"4567"};
		auto p=std::search(s.begin(),s.end(),n.begin(),n.end());
		std::cout<<std::distance(s.begin(),p)<<std::endl;
		p=std::search(s.begin(),s.end(),n.begin(),n.end(),[](const auto a,const auto b){return a==b;});
		std::cout<<std::distance(s.begin(),p)<<std::endl;
	}
	{
		std::string s{"0123765401237654"};
		std::cout<<s<<std::endl;
		std::reverse(s.begin(),s.end());
		std::cout<<s<<std::endl;
		std::sort(s.begin(),s.end());
		std::cout<<s<<std::endl;
		s.erase(std::unique(s.begin(),s.end()),s.end());
		std::cout<<s<<std::endl;
	}
	{
		std::istringstream iss("01234567ABCDEF");
		std::string s;
		std::copy(std::istream_iterator<char>(iss),std::istream_iterator<char>(),std::back_inserter(s));
		std::cout<<s<<std::endl;
	}
	{
		std::istringstream iss("01234567ABCDEF");
		std::string s;
		std::copy_if(std::istream_iterator<char>(iss),std::istream_iterator<char>(),std::back_inserter(s),[](auto a){return a>='0'&&a<='9';});
		std::cout<<s<<std::endl;
	}
	{
		std::istringstream iss("0011   22344556677");
		std::copy(std::istream_iterator<char>(iss),std::istream_iterator<char>(),std::ostream_iterator<char>(std::cout,""));std::cout<<std::endl;
	}
	{
		std::istringstream iss("0011   22344556677");
		std::string s;
		std::unique_copy(std::istream_iterator<char>(iss),std::istream_iterator<char>(),std::back_inserter(s),[](auto a,auto b){return a==b;});
		std::copy(s.begin(),s.end(),std::ostream_iterator<char>(std::cout,""));std::cout<<std::endl;
	}
	{
		std::cout<<std::boolalpha<<std::string().empty()<<std::endl;
		std::cout<<std::boolalpha<<std::string({""}).empty()<<std::endl;
		std::cout<<std::boolalpha<<std::string({"0123"}).empty()<<std::endl;
	}
	{
		std::cout<<std::string("0123").length()<<std::endl;
		std::cout<<std::string("0123").size()<<std::endl;
	}
	{
		std::cout<<std::string().capacity()<<std::endl;
		std::cout<<std::string({""}).capacity()<<std::endl;
		std::cout<<std::string('x',32).capacity()<<std::endl;
	}
	{
		std::cout<<std::string().max_size()<<std::endl;
	}
	{
		std::string s;
		std::cout<<s.capacity()<<std::endl;
		s.reserve(32);
		std::cout<<s.capacity()<<std::endl;
	}
	{
		std::string s;
		s.reserve(32);
		s.append("0123");
		std::cout<<s.capacity()<<std::endl;
		s.shrink_to_fit();
		std::cout<<s.capacity()<<std::endl;
	}
	{
		std::cout<<std::string("0123").compare(std::string("0123"))<<std::endl;
		std::cout<<std::string("0123").compare(std::string("3210"))<<std::endl;
		std::cout<<std::string("0123").compare(2,2,std::string("23"))<<std::endl;
		std::cout<<std::string("0123").compare(2,2,std::string("32"))<<std::endl;
		std::cout<<std::string("0123").compare(2,2,std::string("0123"),2,2)<<std::endl;
		std::cout<<std::string("0123").compare(2,2,std::string("0123"),1,3)<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s[0]='x';
		std::cout<<s<<std::endl;
		s[s.length()-1]='y';
		std::cout<<s<<std::endl;
		s.at(0)='y';
		std::cout<<s<<std::endl;
		s.at(s.length()-1)='x';
		std::cout<<s<<std::endl;
	}
	{
		std::cout<<std::string("0123").front()<<std::endl;
		std::cout<<std::string("0123").back()<<std::endl;
	}
	{
		std::string s0{"0123"};
		std::string s1;
		std::cout<<s1<<std::endl;
		s1.assign(s0);
		std::cout<<s1<<std::endl;
		s1.assign(s0);
		std::cout<<s1<<std::endl;
		s1.assign(s0.begin(),s0.end());
		std::cout<<s1<<std::endl;
		char c[]{"3210"};
		s1.assign(c,sizeof(c)/sizeof(*c));
		std::cout<<s1<<std::endl;
	}
	{
		std::string a{"0123"};
		std::string b{"3210"};
		std::cout<<a<<std::endl;
		std::cout<<b<<std::endl;
		a.swap(b);
		std::cout<<a<<std::endl;
		std::cout<<b<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.append("|");
		std::cout<<s<<std::endl;
		s.append(std::string("3210"),0,2);
		std::cout<<s<<std::endl;
		s.append(std::string("3210"),2,2);
		std::cout<<s<<std::endl;
		char c[]="+|-";
		s.append(c,sizeof(c)/sizeof(*c));
		std::cout<<s<<std::endl;
		s.append(4,':');
		std::cout<<s<<std::endl;
		s.append(s.begin(),s.end());
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.insert(s.length()/2,"xy").insert(s.length()/2,"XY");
		std::cout<<s<<std::endl;
		s.insert(s.length()/2,"ABCD",0,2).insert(s.length()/2,"abcd",0,2);
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.insert(s.length()/2,2,'-').insert(s.length()/2,2,'+');
		std::cout<<s<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.insert(s.begin(),'x');
		s.insert(s.end(),'y');
		s.insert(s.begin()+1,'y');
		s.insert(s.end()-1,'x');
		std::cout<<s<<std::endl;
	}
	{
		std::string a{"0123"};
		std::string b(a.rbegin(),a.rend());
		a.insert(a.begin()+a.size()/2,b.begin(),b.end());
		std::cout<<a<<std::endl;
	}
	{
		std::string s{"0123"};
		s.insert(s.begin()+s.size()/2,{'x','y','z'});
		std::cout<<s<<std::endl;
	}
	{
		std::string a{"0123"};
		std::cout<<a.length()<<std::endl;
		a.clear();
		std::cout<<a.length()<<std::endl;
	}
	{
		std::string a{"0123"};
		std::cout<<a<<std::endl;
		a.erase(2);
		std::cout<<a<<std::endl;
		a.append("23");
		std::cout<<a<<std::endl;
		a.erase(2,2);
		std::cout<<a<<std::endl;
	}
	{
		std::string a{"0123"};
		std::cout<<a<<std::endl;
		a.erase(a.begin()+1,a.end()-1);
		std::cout<<a<<std::endl;
	}
	{
		std::string a{"0123"};
		std::cout<<a<<std::endl;
		a.pop_back();
		std::cout<<a<<std::endl;
	}
	{
		std::string s{"0123"};
		std::cout<<s<<std::endl;
		s.resize(3);
		std::cout<<s<<std::endl;
		s.resize(2);
		std::cout<<s<<std::endl;
		s.resize(1);
		std::cout<<s<<std::endl;
	}
	{
		std::string a{"0123"};
		std::cout<<a<<std::endl;
		a.replace(0,2,"ABCD");
		std::cout<<a<<std::endl;
		a.replace(4,2,"EF");
		std::cout<<a<<std::endl;
		a.replace(a.begin()+1,a.end()-1,"1234");
		std::cout<<a<<std::endl;
		std::string b("4321");
		a.replace(a.begin()+1,a.end()-1,b.begin(),b.end());
		std::cout<<a<<std::endl;
		a.replace(a.begin()+1,a.end()-1,{'x','y','z'});
		std::cout<<a<<std::endl;
	}
	{
		std::string a{"01230123"};
		auto f=[](size_t pos)->std::string{if(pos==std::string::npos)return "Not found";else return "Found: "+std::to_string(pos);};
		std::cout<<f(a.find('1'))<<std::endl;;
		std::cout<<f(a.find('4'))<<std::endl;;
	}
	{
		std::string a{"01230123"};
		auto f=[](size_t pos)->std::string{if(pos==std::string::npos)return "Not found";else return "Found: "+std::to_string(pos);};
		std::cout<<f(a.rfind('1'))<<std::endl;;
		std::cout<<f(a.rfind('4'))<<std::endl;;
	}
	{
		std::string a{"0123ABCD0123ABCDEF0123"};
		auto f=[](size_t pos)->std::string{if(pos==std::string::npos)return "Not found";else return "Found: "+std::to_string(pos);};
		std::cout<<f(a.find("ABCD"))<<std::endl;;
		std::cout<<f(a.rfind("ABCD"))<<std::endl;;
	}
	{
		std::string a{"0123|0123*0123$0123"};
		auto f=[](size_t pos)->std::string{if(pos==std::string::npos)return "Not found";else return "Found: "+std::to_string(pos);};
		std::cout<<f(a.find_first_of("|*$"))<<std::endl;;
		std::cout<<f(a.find_last_of("|*$"))<<std::endl;;
	}
	{
		std::string a{"0123|0123*0123$0123"};
		auto f=[](size_t pos)->std::string{if(pos==std::string::npos)return "Not found";else return "Found: "+std::to_string(pos);};
		std::cout<<f(a.find_first_not_of("0123456789"))<<std::endl;;
		std::cout<<f(a.find_last_not_of("0123456789"))<<std::endl;;
	}
	return 0;
}
