#include<iostream>
#include<cstring>
#if __cplusplus >= 201703L && __has_include(<filesystem>)
#include<filesystem>
namespace filesystem=std::filesystem;
#else
#include<experimental/filesystem>
namespace filesystem=std::experimental::filesystem;
#endif
#include"tinyxml2/tinyxml2.h"
std::string getver(std::string path){
	std::string ret="?";
	const char ndl[]="Mendix";
	tinyxml2::XMLDocument doc;
	if(doc.LoadFile(path.c_str())==tinyxml2::XML_SUCCESS){
		auto cpe=doc.FirstChildElement("classpath");
		const char*ndl=nullptr;
		if((cpe=cpe->FirstChildElement("classpathentry"))!=nullptr){
			do{
				auto k=cpe->FindAttribute("kind");
				if(!k)continue;
				auto*v=k->Value();
				if(!v)continue;
				if(strcmp(v,"lib")==0){
					k=cpe->FindAttribute("path");
					auto*v=k->Value();
					if(!v)continue;
					if(strcmp(v,"path")){
						if(strstr(v,"Mendix")!=nullptr){
							ndl=v;
						}
					}
				}
			}while((cpe=cpe->NextSiblingElement())!=nullptr&&ndl==nullptr);
			if(ndl!=nullptr){
				char*tok=strtok((char*)ndl,"/");
				char*ver=nullptr;
				while(tok!=nullptr){
					if(strcmp(tok,"Mendix")==0){
						tok=strtok(NULL,"/");
						if(tok!=nullptr){
							ver=tok;
						}
						break;
					}
					tok=strtok(NULL,"/");
				}
				if(ver!=nullptr){
					ret=ver;
				}else{
					std::cerr<<"failed to obtain version"<<std::endl;
				}
			}else{
				std::cerr<<"not found"<<std::endl;
			}
		}else{
			std::cerr<<"classpath not found"<<std::endl;
		}
	}else{
		std::cerr<<"Failed to open file"<<std::endl;
	}
	return ret;

}
int main(int argc,char**argv){
	std::string path=".";
	if(argc==2)path=argv[1];
	for(const auto&ent:filesystem::recursive_directory_iterator(path)){
		//std::cout<<"scanning "<<ent.path().string()<<std::endl;
		//if(ent.path().extension()==".classpath"){
		//std::cout<<ent.path().filename().string()<<std::endl;
		if(ent.path().filename().string()==".classpath"){
			std::cout<<ent.path().string()<<":"<<getver(ent.path().string())<<std::endl;
		}
	}
	return 0;
}
