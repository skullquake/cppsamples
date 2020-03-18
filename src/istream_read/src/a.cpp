#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
struct Foo{
	int bar;
	float baz;
	char qux[16];
};
//--------------------------------------
class Bar{
	public:
		Bar(int barP=0,float bazP=0.0,std::string quxP="");
		void print()const;
		void save(std::ofstream& outf)const;
		void load(std::ifstream& inf);
	private:
		int bar;
		float baz;
		std::string qux;
};
Bar::Bar(int barP,float bazP,std::string quxP)
    :bar(barP),
     baz(bazP),
     qux(quxP)
{}
void Bar::print()const{
	std::cout<<"["
	         <<bar<<","
	         <<baz<<","
	         <<qux
	         <<"]"
	         <<std::endl;
}
void Bar::save(std::ofstream& outf)const{
	outf.write((char*)&bar,sizeof(bar));
	outf.write((char*)&baz,sizeof(baz));
	outf.write(qux.c_str(),qux.size()+1);
};
void Bar::load(std::ifstream& inf){
	inf.read((char*)&bar,sizeof(bar));
	inf.read((char*)&baz,sizeof(baz));
	std::stringstream ss;
	char c;
	do{
		inf.read(&c,1);
		ss<<c;
	}while(c!='\0');
	qux=ss.str();
};
//--------------------------------------
int main(int argc,char** argv){
	//writing char array
	{
		std::ofstream outf("./char.bin",std::ios::binary);
		if(outf.is_open()){
			char buf[32];
			for(int i=0;i<sizeof(buf)/sizeof(buf[0]);i++){
				buf[i]='a'+i;
			}
			outf.write(buf,sizeof(buf)/sizeof(buf[0]));
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//reading a char array hardcoded len
	{
		std::ifstream inf("./char.bin",std::ios::binary);
		if(inf.is_open()){
			char buf[32];
			inf.read(buf,sizeof(buf)/sizeof(buf[0]));
			inf.close();
			for(auto c:buf){
				std::cout<<c<<" ";
			}
			std::cout<<std::endl;
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//reading a char array dynamic len
	{
		std::ifstream inf("./char.bin",std::ios::binary);
		if(inf.is_open()){
			inf.seekg(0,std::ios::end);
			int fsz=inf.tellg();
			inf.seekg(0,std::ios::beg);
			int nel=fsz/sizeof(char);
			char *buf=new char[nel];
			inf.read(buf,fsz);
			inf.close();
			for(int i=0;i<nel;i++){
				std::cout<<buf[i]<<" ";
			}
			delete [] buf;
			std::cout<<std::endl;
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing uint8 array
	{
		std::ofstream outf("./uint8_t.bin",std::ios::binary);
		if(outf.is_open()){
			uint8_t buf[8];
			for(int i=0;i<sizeof(buf)/sizeof(buf[0]);i++){
				buf[i]=(uint8_t)i;
			}
			outf.write((char*)buf,sizeof(buf)/sizeof(buf[0]));
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//reading a uint8 array dynamic len
	{
		std::ifstream inf("./uint8_t.bin",std::ios::binary);
		if(inf.is_open()){
			inf.seekg(0,std::ios::end);
			int fsz=inf.tellg();
			inf.seekg(0,std::ios::beg);
			int nel=fsz/sizeof(uint8_t);
			std::cout<<fsz<<std::endl;
			std::cout<<nel<<std::endl;
			uint8_t *buf=new uint8_t[nel];
			inf.read((char*)buf,fsz);
			inf.close();
			for(int i=0;i<nel;i++){
				std::cout<<(int)buf[i]<<" ";
			}
			delete [] buf;
			std::cout<<std::endl;
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing struct array
	{
		std::ofstream outf("./foo.bin",std::ios::binary);
		if(outf.is_open()){
			struct Foo buf[]={
				{0,1.1,"Foo"},
				{1,2.2,"Bar"},
				{1,3.3,"Baz"},
				{2,4.4,"Qux"},
				{3,5.5,"Klutz"}
			};
			outf.write((char*)buf,sizeof(Foo)*sizeof(buf)/sizeof(buf[0]));
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing class object
	{
		std::ofstream outf("./bar.bin",std::ios::binary);
		if(outf.is_open()){
			auto b=Bar{0,1.1,"Foo"};
			b.print();
			b.save(outf);
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//reading class array
	{
		std::ifstream inf("./bar.bin",std::ios::binary);
		if(inf.is_open()){
			Bar b;
			b.load(inf);
			b.print();
			inf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing class array
	{
		std::ofstream outf("./bararr.bin",std::ios::binary);
		if(outf.is_open()){
			std::vector<Bar> buf={
				{0,1.1,"Foo"},
				{1,2.2,"Bar"},
				{2,3.3,"Baz"}
			};
			for(auto b:buf){
				b.print();
				b.save(outf);
			}
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//reading class array
	{
		std::ifstream inf("./bararr.bin",std::ios::binary);
		if(inf.is_open()){
			std::vector<Bar> buf;
			inf.seekg(0,std::ios::end);
			int fsz=inf.tellg();
			inf.seekg(0,std::ios::beg);
			while(inf.tellg()!=fsz){
				std::cout<<inf.tellg()<<std::endl;
				Bar b;
				b.load(inf);
				buf.push_back(b);
			}
			for(auto b:buf){
				b.print();
			}
			inf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	return 0;
}
