/*
 * here we look at std::istream_iterator used in reading input streams from files
 * written using std::ostream_iterator and std::copy
 */
#include<iostream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<sstream>
//------------------------------------------------------------------------------
struct Foo{
	uint8_t bar;
	uint32_t baz;
	float qux;
	char klutz[8];
};
std::ostream& operator<<(std::ostream& outs,const Foo& foo){
	outs.write((char*)&(foo.bar),sizeof(foo.bar));
	outs.write((char*)&(foo.baz),sizeof(foo.baz));
	outs.write((char*)&(foo.qux),sizeof(foo.qux));
	outs.write(foo.klutz,sizeof(foo.klutz));
	return outs;
}
std::istream& operator>>(std::istream & ins, Foo& foo){
	ins.read((char*)&(foo.bar),sizeof(foo.bar));
	ins.read((char*)&(foo.baz),sizeof(foo.baz));
	ins.read((char*)&(foo.qux),sizeof(foo.qux));
	ins.read(foo.klutz,sizeof(foo.klutz));
	return ins;
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
		void print(){
			std::cout<<"["
			         <<(int)bar<<","
			         <<(int)baz<<","
			         <<qux<<","
			         <<klutz
			         <<"]"
			         <<std::endl
			;
		};
		friend std::ostream& operator<<(std::ostream &outs,const Bar &b); 
		friend std::istream& operator>>(std::istream& inst,Bar& bar);
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

std::ostream& operator<<(std::ostream& outs,const Bar& b){   
	outs.write((char*)&(b.bar),sizeof(b.bar));
	outs.write((char*)&(b.baz),sizeof(b.baz));
	outs.write((char*)&(b.qux),sizeof(b.qux));
	outs.write(b.klutz.c_str(),b.klutz.size()+1);
	return outs;
}
std::istream& operator>>(std::istream & ins, Bar& bar){
	ins.read((char*)&(bar.bar),sizeof(bar.bar));
	ins.read((char*)&(bar.baz),sizeof(bar.baz));
	ins.read((char*)&(bar.qux),sizeof(bar.qux));
	std::stringstream ss;
	char c;
	do{
		ins.read(&c,1);
		ss<<c;
	}while(c!='\0');
	bar.klutz=ss.str();
	return ins;
}
//------------------------------------------------------------------------------
int main(int argc,char** argv){
	//writing std::vector uint8_t
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
	//reading std::vector uint8_t
	{
		std::ifstream inf("./uint8_t.bin",std::ios::binary);
		if(inf.is_open()){
			std::vector<uint8_t> buf;
			std::istream_iterator<uint8_t> isi(inf);
			std::copy(
				isi,
				std::istream_iterator<uint8_t>(),//end of stream iterator
				std::back_inserter(buf)
			);
			inf.close();
			for(auto a:buf){
				std::cout<<(int)a<<" ";
			}
			std::cout<<std::endl;
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
	//reading std::vector struct
	{
		std::ifstream inf("./struct.bin",std::ios::binary);
		if(inf.is_open()){
			std::vector<struct Foo> buf;
			std::istream_iterator<struct Foo> isi(inf);
			std::copy(
				isi,
				std::istream_iterator<struct Foo>(),//end of stream iterator
				std::back_inserter(buf)
			);
			inf.close();
			for(auto a:buf){
				std::cout<<"["
				         <<(int)a.bar<<","
				         <<(int)a.baz<<","
				         <<a.qux<<","
				         <<a.klutz<<","
				         <<"]"
				         <<" "
				;
			}
			std::cout<<std::endl;
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
	//reading std::vector class
	{
		std::ifstream inf("./class.bin",std::ios::binary);
		if(inf.is_open()){
			std::vector<Bar> buf;
			std::istream_iterator<Bar> isi(inf);
			std::copy(
				isi,
				std::istream_iterator<Bar>(),//end of stream iterator
				std::back_inserter(buf)
			);
			inf.close();
			for(auto a:buf){
				a.print();
			}
			std::cout<<std::endl;
		}else{
			std::cerr<<"Error: Could not open file"<<std::endl;
		}
	}

	return 0;
}
