#include<iostream>
#include<fstream>
struct Foo{
	int bar;
	float baz;
	char qux[80];
};
int main(int argc,char** argv){
	//writing char array
	{
		std::ofstream outf("./out.bin",std::ios::binary);
		if(outf.is_open()){
			char buf[32];
			for(int i=0;i<sizeof(buf)/sizeof(buf[0]);i++){
				buf[i]=i;
			}
			outf.write(buf,sizeof(buf)/sizeof(buf[0]));
			outf.close();
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
	return 0;
}
