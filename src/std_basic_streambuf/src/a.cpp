#include<iostream>
#include<sstream>
#include<cstdlib>
class SB0:public std::streambuf{
	protected:
		virtual int_type overflow(int_type c){
			if(c!=EOF){
				c=std::toupper(c/*,getloc()*/);
				if(std::putchar(c)==EOF){
					return EOF;
				}
			}
			return c;
		};
};
template<typename CharT,typename traits=std::char_traits<char>>
class SB1:public std::basic_streambuf<CharT,traits>{
	protected:
		virtual typename traits::int_type overflow(typename traits::int_type c){
			if(!traits::eq_int_type(c,traits::eof())){
				c=std::toupper(c/*,this->getloc()*/);
				char cc=std::use_facet<std::ctype<CharT>>(this->getloc()).narrow(c,'?');
				if(std::putchar(c)==EOF){
					return traits::eof();
				}
			}
			return traits::not_eof(c);
		};

};
typedef SB1<char>    SB1N;
typedef SB1<wchar_t> SB1W;
int main(void){
	{//writing to stream buffer
		auto buf=std::cout.rdbuf();
		char a[]="01234567890abcdef";
		if((buf->sputn(a,sizeof(a)))<(long int)(sizeof(a)/sizeof(*a))){std::cerr<<"error"<<std::endl;}
		if(!(buf->sputc('\n'))){std::cerr<<"error"<<std::endl;}
	}
	{//reading from stream buffer
		std::istringstream iss("0123456789abcdef");
		auto buf=iss.rdbuf();
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		std::cout<<"chr:"<<buf->sgetc()<<std::endl;	//return cur
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		std::cout<<"chr:"<<buf->sbumpc()<<std::endl;	//return cur,consume cur
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		std::cout<<"chr:"<<buf->snextc()<<std::endl;	//return next,consume cur
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		char cbuf[5];
		size_t n=buf->sgetn(cbuf,sizeof(cbuf)-1);	//read n into buf,return num read
		cbuf[sizeof(cbuf)-1]='\0';			//terminate
		std::cout<<"chr:read:"<<n<<":val:"<<cbuf<<std::endl;
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		buf->sputbackc('X');				//returns char to stream buffer
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
		buf->sungetc();					//steps back to prev chr in stream buffer
		std::cout<<"avl:"<<buf->in_avail()<<std::endl;	//return available
	}
	{//manipulate locale
		std::istringstream iss("0123456789abcdef");
		auto buf=iss.rdbuf();
		auto loc=buf->getloc();		//get locale
		auto locprv=buf->pubimbue(loc);	//set locale, returns prv locale
	}
	{//manipulate position
		std::istringstream iss("0123456789abcdef");
		auto buf=iss.rdbuf();
		std::string s;
		//repos abs - returns stream position
		if(buf->pubseekpos(8)!=std::ios::pos_type(std::ios::off_type(-1))){
			iss>>s;
			std::cout<<s<<std::endl;
		}else{
			std::cout<<"invalid position"<<std::endl;
		}
	}
	{//manipulate position
		std::istringstream iss("0123456789abcdef");
		auto buf=iss.rdbuf();
		//repos rel - returns stream position
		if(buf->pubseekoff(8,std::ios::beg)!=std::ios::pos_type(std::ios::off_type(-1))){//??
			std::string s;
			iss>>s;
			std::cout<<s<<std::endl;
		}else{
			std::cout<<"invalid position"<<std::endl;
		}
	}
	{//manipulate buffering - test using strace ./bin/a.out
		std::ostringstream oss;
		auto buf=oss.rdbuf();
		char cbuf[8];
		buf->pubsetbuf(cbuf,0);			//set 8b buf
		oss<<"0123456789abcdef";
	}
	{//manipulate buffering - test using strace ./bin/a.out
		std::ostringstream oss;
		auto buf=oss.rdbuf();
		buf->pubsetbuf(nullptr,0);		//disable buffering
		oss<<"0123456789abcdef";
	}
	{//custom stream buffer
		SB0 sb;
		std::ostream os(&sb);
		os<<"0123456789abcdef"<<std::endl;
	}
	{//custom stream buffer
		SB1<char> sb;
		std::ostream os(&sb);
		os<<"0123456789abcdef"<<std::endl;
	}
	{//custom stream buffer
		SB1N sb;
		std::ostream os(&sb);
		os<<"0123456789abcdef"<<std::endl;
	}
	{//custom stream buffer
		SB1W sb;
		//std::owstream os(&sb);
		//os<<"0123456789abcdef"<<std::endl;
	}

	return EXIT_SUCCESS;
}
