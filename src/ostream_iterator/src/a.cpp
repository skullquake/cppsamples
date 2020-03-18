/*
 * here we look at std::ostream_iterator as used in writing to output streams
 */
#include<iostream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<vector>
#include<stdio.h>
//------------------------------------------------------------------------------
struct Foo{
	uint8_t bar;
	uint32_t baz;
	float qux;
	char klutz[8];
};
std::ostream& operator<<(std::ostream& os,const Foo& foo){   
	os.write((char*)&(foo.bar),sizeof(foo.bar));
	os.write((char*)&(foo.baz),sizeof(foo.bar));
	os.write((char*)&(foo.qux),sizeof(foo.bar));
	os.write(foo.klutz,sizeof(foo.klutz));
	os<<"|";
	return os;
}
//------------------------------------------------------------------------------
class Bar{
	public:
		Bar(
			uint8_t barP=0,
			uint32_t bazP=2,
			float quxP=3.4,
			std::string klutzP="foo"
		);
		friend std::ostream& operator<<(std::ostream &outs,const Bar &b); 
		//friend std::istream& operator>>(ins &in,Bar& b); 
	private:
		uint8_t bar;
		uint32_t baz;
		float qux;
		std::string klutz;
};
Bar::Bar(
	uint8_t barP,
	uint32_t bazP,
	float quxP,
	std::string klutzP
)
    :bar(barP),
     baz(bazP),
     qux(quxP),
     klutz(klutzP)
{}

//friend std::istream& operator>>(ins &in,Bar& b); 
std::ostream& operator<<(std::ostream& outs,const Bar& b){   
	outs.write((char*)&(b.bar),sizeof(b.bar));
	outs.write((char*)&(b.baz),sizeof(b.baz));
	outs.write((char*)&(b.qux),sizeof(b.qux));
	outs.write(b.klutz.c_str(),b.klutz.size()+1);
	/*
	//os.write(foo.klutz,sizeof(foo.klutz));
	//os<<"|";
	*/
	return outs;
}
//------------------------------------------------------------------------------
int main(int argc,char** argv){
	//writing std::vecto unint8_t
	{
		std::ofstream outf("./uint8_t.bin",std::ios::binary|std::ios::out);
		if(outf.is_open()){
			std::vector<uint8_t> buf(32);
			std::iota(std::begin(buf),std::end(buf),0);
			std::ostream_iterator<uint8_t> osi(outf);
			std::copy(buf.begin(),buf.end(),osi);
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing std::vector struct
	{
		std::ofstream outf("./struct.bin",std::ios::binary|std::ios::out);
		if(outf.is_open()){
			std::vector<struct Foo> buf;
			for(int i=0;i<8;i++){
				struct Foo b;
				b.bar=0;
				b.baz=1;
				b.qux=2.3;
				buf.push_back(b);
				sprintf(b.klutz,"foo");
			}
			std::ostream_iterator<struct Foo> osi(outf);
			std::copy(buf.begin(),buf.end(),osi);
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	//writing std::vector class
	{
		std::ofstream outf("./class.bin",std::ios::binary|std::ios::out);
		if(outf.is_open()){
			std::vector<Bar> buf;
			for(int i=0;i<8;i++){
				Bar b(0,1,2.3,"foo");
				buf.push_back(b);
			}
			std::ostream_iterator<Bar> osi(outf);
			std::copy(buf.begin(),buf.end(),osi);
			outf.close();
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}
	return 0;
}
