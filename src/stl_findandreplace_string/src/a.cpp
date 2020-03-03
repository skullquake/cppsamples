#include<iostream>
#include<string>
size_t findCaseInsensitive(std::string data,std::string toSearch, size_t pos=0){
	std::transform(data.begin(),data.end(),data.begin(),::tolower);
	std::transform(toSearch.begin(),toSearch.end(),toSearch.begin(),::tolower);
	return data.find(toSearch,pos);
}
void findAndReplaceAll(std::string &data,std::string toSearch,std::string replaceStr,bool caseInsensitive=false){
	size_t pos=caseInsensitive?findCaseInsensitive(data,toSearch):data.find(toSearch);
	while(pos!=std::string::npos){//end of string
		data.replace(pos,toSearch.size(),replaceStr);
		pos=caseInsensitive?findCaseInsensitive(data,toSearch,pos+replaceStr.size()):data.find(pos+replaceStr.size())
		;
	}
}
int main(int argc,char** argv){
	std::string data="Boost Library is simple C++ Library";
	std::cout<<data<<std::endl;
	findAndReplaceAll(data,"Lib","XXX");
	findAndReplaceAll(data,"xxx","zzz",false);
	findAndReplaceAll(data,"xxx","###",true);
	std::cout<<data<<std::endl;
	return 0;
}
