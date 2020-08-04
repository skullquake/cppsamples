#include<iostream>
#include<memory>
#include<cstdlib>
class S{
	public:
		S(int pa=0,std::shared_ptr<S>pnext=nullptr):ma(pa),mnext(pnext){
			std::cout<<"S::S:  "<<this<<" "<<mnext<<" "<<ma<<std::endl;
		};
		~S(){
			std::cout<<"S::~S: "<<this<<" "<<mnext<<" "<<ma<<std::endl;
		};
		void setnext(std::shared_ptr<S>pnext){
			mnext=pnext;
		};
	private:
		int ma;
		std::shared_ptr<struct S>mnext;
};
void f(std::weak_ptr<int>a){
	if(std::shared_ptr<int>b=a.lock()){
		std::cout<<"f:available"<<std::endl;
	}else{
		std::cout<<"f:not available"<<std::endl;
	}
}
int main(void){
	{
		std::shared_ptr<int>a(new int);
		*a=42;
		f(a);
	}
	{
		std::shared_ptr<S>a(new S(0));
		std::shared_ptr<S>b(new S(1));
		std::shared_ptr<S>c(new S(2));
		std::shared_ptr<S>d(new S(3));
		a->setnext(b);
		b->setnext(c);
	}
	{//check destruction of these
		std::shared_ptr<S>a(new S(10));
		std::shared_ptr<S>b(new S(11));
		std::shared_ptr<S>c(new S(12));
		std::shared_ptr<S>d(new S(13));
		a->setnext(b);
		b->setnext(c);
		c->setnext(a);
	}
	return EXIT_SUCCESS;
}
