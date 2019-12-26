#include<iostream>
namespace nsa{
	void a(){std::cout<<"nsa::a()"<<std::endl;}
}
namespace nsb{
	void a(){std::cout<<"nsb::a()"<<std::endl;}
}
namespace nsc{
	void a(){std::cout<<"nsc::a()"<<std::endl;}
	namespace nsd{
		void a(){std::cout<<"nsc::nsd::a()"<<std::endl;}
	}
}
//-std=c++17
namespace nse::nsf{
	void a(){std::cout<<"esg::fsh::a()"<<std::endl;}
}
namespace nsg::nsh::nsi{
	void a(){std::cout<<"nsg::nsh::nsi::a()"<<std::endl;}
}
int main(int argc,char** argv){
	nsa::a();
	nsb::a();
	nsc::a();
	nsc::nsd::a();
	{
		using namespace nsa;
		a();
	}
	{
		using namespace nsb;
		a();
	}
	{
		using namespace nsc;
		a();
		nsd::a();
	}
	{
		using namespace nsa;
		nsa::a();
		nsb::a();
		nsc::a();
		nsc::nsd::a();
	}
	::nsa::a();
	::nsb::a();
	::nsc::a();
	::nsc::nsd::a();
	//-std=c++17
	nse::nsf::a();
	nsg::nsh::nsi::a();
	::nse::nsf::a();
	::nsg::nsh::nsi::a();
	return 0;
}
