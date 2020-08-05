#include<iostream>
#include<cstdlib>
#include<regex>
#include<string>
#include<algorithm>
#include<iomanip>
int main(void){
	{//match basic - complete match
		std::regex r(R"(A.*)");
		std::cout<<std::boolalpha<<std::regex_match(R"(A0123)",r)<<std::endl;
		std::cout<<std::boolalpha<<std::regex_match(R"(B0123)",r)<<std::endl;
	}
	{//grammer specification
		std::regex(R"(.*)",std::regex_constants::grep);
		std::regex(R"(.*)",std::regex_constants::egrep);
		std::regex(R"(.*)",std::regex_constants::awk);
		std::regex(R"(.*)",std::regex_constants::nosubs);
		std::regex(R"(.*)",std::regex_constants::optimize);
		std::regex(R"(.*)",std::regex_constants::icase);
		std::regex(R"(.*)",std::regex_constants::collate);
		std::regex(R"(.*)",std::regex_constants::ECMAScript);
		std::regex(R"(.*)",std::regex_constants::basic);
		std::regex(R"(.*)",std::regex_constants::extended);
	}
	{//match oneliner
		std::cout<<std::boolalpha<<std::regex_match(R"(A0123)",std::regex(R"(A.*)"))<<std::endl;
		std::cout<<std::boolalpha<<std::regex_match(R"(B0123)",std::regex(R"(A.*)"))<<std::endl;
	}
	{
		std::string l=R"(B0123)";
		std::cout<<std::boolalpha<<std::regex_match(l.begin(),l.end(),std::regex(R"(A.*)"))<<std::endl;
	}
	{//search - partial match
		std::cout<<std::regex_match(R"(A0123)",std::regex(R"(A.*)"))      <<" "<<std::regex_search(R"(A0123)",std::regex(R"(A.*)"))      <<std::endl;
		std::cout<<std::regex_match(R"(B0123)",std::regex(R"(A.*)"))      <<" "<<std::regex_search(R"(B0123)",std::regex(R"(A.*)"))      <<std::endl;
		std::cout<<std::regex_match(R"(B0123A0123)",std::regex(R"(A.*)")) <<" "<<std::regex_search(R"(B0123A0123)",std::regex(R"(A.*)")) <<std::endl;
		std::cout<<std::regex_match(R"(A0123B0123)",std::regex(R"(A.*)")) <<" "<<std::regex_search(R"(A0123B0123)",std::regex(R"(A.*)")) <<std::endl;
	}
	{//return details of match
		std::smatch m;
		std::regex r(R"((A.B))");
		std::string l(R"(01AXB23AYB45AZB67)");
		if(std::regex_search(l,m,r)){
			std::cout<<"Found"<<std::endl;
			std::cout<<"str:"<<m.str()<<std::endl;
			std::cout<<"len:"<<m.length()<<std::endl;
			std::cout<<"pos:"<<m.position()<<std::endl;
			std::cout<<"pfx:"<<m.prefix().str()<<std::endl;
			std::cout<<"sfx:"<<m.suffix().str()<<std::endl;
			std::cout<<"siz:"<<m.size()<<std::endl;
			std::cout<<"rdy:"<<m.ready()<<std::endl;
			std::cout<<"mty:"<<m.empty()<<std::endl;
			std::cout<<"siz:"<<m.size()<<std::endl;
			std::cout<<"msz:"<<m.max_size()<<std::endl;
			size_t i=0;
			for(auto pos=m.begin();pos!=m.end();++pos){
				std::cout<<"\t\t["<<i<<"]*:  "<<(*pos)<<std::endl;
				std::cout<<"\t\t["<<i<<"]str:"<<pos->str()<<std::endl;
				std::cout<<"\t\t["<<i<<"]len:"<<pos->length()<<std::endl;
				++i;
			}std::cout<<std::string(80,'-')<<std::endl;
			for(i=0;i<m.size();++i){
				std::cout<<"\t\t["<<i<<"]str:  "<<m[i].str()<<std::endl;
				std::cout<<"\t\t["<<i<<"]str:  "<<m.str(i)<<std::endl;
				std::cout<<"\t\t["<<i<<"]pos:  "<<m.position(i)<<std::endl;
				std::cout<<"\t\t["<<i<<"]len:  "<<m.length(i)<<std::endl;
			}std::cout<<std::string(80,'-')<<std::endl;
			l.replace(m.position(),m.length(),"XYZ");
			std::cout<<l<<std::endl;
		}else{
			std::cout<<"Not found"<<std::endl;
		}
	}
	{//sregex_iterator
		std::regex r(R"((A.B))");
		std::string s(R"(01AXB23AYB45AZB67)");
		for(std::sregex_iterator i=std::sregex_iterator(s.begin(),s.end(),r);i!=std::sregex_iterator();++i){
			std::cout<<std::left<<s<<":"<<std::setw(8)<<i->position()<<":"<<std::setw(8)<<i->length()<<":"<<i->str()<<std::endl;
		}
	}
	{//replace
		std::regex r(R"((AB))");
		std::string l(R"(01AB23AB45AB67)");
		std::cout<<std::regex_replace(l,r,"XX")<<std::endl;
		std::string s;
		std::regex_replace(std::back_inserter(s),l.begin(),l.end(),r,"YY");
		std::cout<<s<<std::endl;
	}
	return EXIT_SUCCESS;
}
