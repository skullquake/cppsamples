#include<iostream>
#include<fstream>
struct Foo{
	int bar;
	float baz;
	char qux[16];
};
int main(int argc,char** argv){
	//writing char array
	{
		std::ofstream outf("./char.bin",std::ios::binary);
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
