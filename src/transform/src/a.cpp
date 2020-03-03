#include<iostream>
#include<vector>
#include<map>
char fnup(char c){
	return ::toupper(c);
}
char fnlo(char c){
	return ::tolower(c);
}
int main(int argc,char** argv){
	//std::string example
	{
		std::string data="Lorem Ipsum Sit Consecutar Dolor Amet";
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),::tolower);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),::toupper);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),fnlo);
		std::cout<<data<<std::endl;
		std::transform(data.begin(),data.end(),data.begin(),fnup);
		std::cout<<data<<std::endl;

		int idx=0;
		std::transform(data.begin(),data.end(),data.begin(),[&](char&c){
				return idx++%2?char(::tolower(c)):char(::toupper(c));
		});
		std::cout<<data<<std::endl;
	}
	//binary operation
	{
		std::cout<<"binary itr,itr,itr,itr,itr,op:"<<std::endl;
		std::vector<int> v0={0,1,2,3};
		std::vector<int> v1={0,2,4,8};
		std::vector<int> v2;
		v2.resize(v0.size());
		for(auto a:v0){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		for(auto a:v1){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		std::transform(v0.begin(),v0.end(),v1.begin(),v2.begin(),[](int a,int b){
				return a+b;
		});
		for(auto a:v2){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
	}
	//different types of containers
	{
		std::cout<<"different containers:"<<std::endl;
		std::map<std::string,int>  m={
			std::make_pair("A",0),
			std::make_pair("B",2),
			std::make_pair("C",4),
			std::make_pair("D",8)
		};
		std::vector<int> v;
		v.resize(m.size());
		std::transform(m.begin(),m.end(),v.begin(),[](auto a){return a.second;});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;
		v.clear();
		std::transform(m.begin(),m.end(),std::back_inserter(v),[](auto a){return a.second;});
		for(auto a:v){
			std::cout<<a<<" ";
		}
		std::cout<<std::endl;

	}
	return 0;
}

