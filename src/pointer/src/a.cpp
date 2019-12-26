/*
 * raw pointers are only used if not ownership is involved
 * see also shared pointers and unique pointers
 */

#include<iostream>
struct B{
	int a;
	int b;
	int c;
};
int main(int argc,char** argv){
	int* a=nullptr;
	a=new int;
	if(a!=nullptr){
		*a=1;
		std::cout<<*a<<std::endl;
		delete a;
	}else{
		std::cerr<<"Failed to allocate a"<<std::endl;
	}
	B* b=nullptr;
	b=new B;
	if(b!=nullptr){
		b->a=1;
		b->b=2;
		b->c=3;
		std::cout<<b->a<<std::endl;
		std::cout<<b->b<<std::endl;
		std::cout<<b->c<<std::endl;
		delete b;
	}else{
		std::cerr<<"Failed to allocate b"<<std::endl;
	}
	int csz=4;
	int* c=nullptr;
	c=new int[csz];
	if(c!=nullptr){
		for(int i=0;i<csz;i++){
			c[i]=i;
		}
		for(int i=0;i<csz;i++){
			std::cout<<c[i]<<std::endl;
		}
		delete c;
	}else{
		std::cerr<<"Failed to allocate c"<<std::endl;
	}
	int dsz=4;
	B* d=nullptr;
	d=new B[dsz];
	if(d!=nullptr){
		for(int i=0;i<dsz;i++){
			d[i].a=i;
			d[i].b=i+1;
			d[i].c=i+2;
		}
		for(int i=0;i<dsz;i++){
			std::cout<<d[i].a<<std::endl;
			std::cout<<d[i].b<<std::endl;
			std::cout<<d[i].c<<std::endl;
		}
		delete d;
	}else{
		std::cerr<<"Failed to allocate d"<<std::endl;
	}
	return 0;
}
