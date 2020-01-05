/*
 * {} for initizliation
 */
#include<iostream>
#include<vector>
struct A{
	int a;
	float b;
};
class B{
	public:
		B(int aP=0,float bP=0.0)
		:m_a(aP),
		 m_b(bP){
		};
		~B(){
		};
	private:
		int m_a;
		float m_b;
	protected:
};
int main(int argc,char** argv){
	A a{0,1.1};
	B b{0,1.1};
	int c{0};
	int d[4]{0,1,2,3};
	int e[]{0,1,2,3};
	std::vector f{1,2,3,4};
	return 0;
}
