#include<iostream>
#include<vector>
#include<range/v3/all.hpp>
//--------------------------------------------------------------------------------
//class for class member function functor test
//--------------------------------------------------------------------------------
class A{
	public:
		A(int maP):ma(maP){};
		int get_ma()const{return this->ma;};
	private:
		int ma;
};
//--------------------------------------------------------------------------------
//end class
//--------------------------------------------------------------------------------
int main(int argc,char** argv){
	//class member function test [std::mem_fn]
	{
		std::vector<A> a={
			A(0),
			A(1),
			A(2),
			A(3)
		};
		auto b=
			 a
			|ranges::views::transform(&A::get_ma)
		;
		std::cout<<"Class member ranges::views::transform:"<<std::endl;
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}

