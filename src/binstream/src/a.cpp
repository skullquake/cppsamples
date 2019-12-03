#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
using namespace std;
template<class T,class CharT=char,class Traits=std::char_traits<CharT>>
class ostreambin_iterator:
	public std::iterator<std::output_iterator_tag,void,void,void,void> {
public:
	typedef std::basic_ostream<CharT,Traits> ostream_type;
	typedef Traits traits_type;
	typedef CharT char_type;
	ostreambin_iterator(ostream_type& stream):stream_(stream) { }
	ostreambin_iterator& operator=(T const& value){
		stream_.write(reinterpret_cast<const char*>(&value),sizeof(T));
		return *this;
	}
	ostreambin_iterator& operator*(){return *this;}
	ostreambin_iterator& operator++(){return *this;}
	ostreambin_iterator& operator++(int){return *this;}
protected:
	ostream_type& stream_;
};
int main(int argc,char** argv){
	{
		std::vector<long> d(3);
		d[0] = 0x303030;
		d[1] = 0x31;
		d[2] = 0x32;
		ostreambin_iterator<long> out(cout);
		copy(std::begin(d), std::end(d), out);
	}
	{
		std::vector<float> f(3);
		f[0] = 0.0;
		f[1] = 0.1;
		f[2] = 0.2;
		ostreambin_iterator<long> out(cout);
		copy(std::begin(f),std::end(f),out);
	}
	return 0;
}
