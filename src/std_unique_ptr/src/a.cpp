#include<iostream>
#include<memory>
class C{
	public:
		C(int pa=0):ma(pa){std::cout<<"C::C():"<<ma<<std::endl;};
		~C(){std::cout<<"C::~C():"<<ma<<std::endl;};
	private:
		int ma;
};
int main(int argc,char** argv){
	{
		std::unique_ptr<C> a();
		std::unique_ptr<C> b(new C(0));
		std::unique_ptr<C> c=std::make_unique<C>(1);
		std::unique_ptr<C> d(std::move(b));
	}
	{
		C*a=new C(42);
		std::unique_ptr<C>b(a);
	}
	{
		C*a=new C(42);
		std::unique_ptr<C>b(std::move(a));
	}
	{
		C*a=new C(43);
		std::unique_ptr<C>b(a);
		std::unique_ptr<C>c(a);//!
	}
	{
		std::unique_ptr<C>a(new C(44));
		std::unique_ptr<C>b([](){return new C(45);}());
		//std::unique_ptr<C>c=std::make_unique<C>(46);//?
		//auto d=std::make_unique<C>(47);//?
		std::unique_ptr<C>e(std::move(a));
	}
	return 0;
}
