#include<iostream>
class A{
	public:
		A()
		:m_a(0),
		 m_b(0)
		{
			std::cout<<"A()"<<std::endl;
		};
		~A(){
			std::cout<<"~A()"<<std::endl;
		};
		void set_a(int aP){
			this->m_a=aP;
		}
		const int& get_a() const{
			return this->m_a;
		}
		void set_b(int bP){
			this->m_b=bP;
		}
		const int& get_b() const{
			return this->m_b;
		}
	private:
		int m_a;
		int m_b;
	protected:
};
int main(int argc,char** argv){
	A a;
	a.set_a(8);
	a.set_b(16);
	std::cout<<a.get_a()<<std::endl;
	std::cout<<a.get_b()<<std::endl;
	return 0;
}
