/*
 * instead of using raw pointer, you can use shared pointers in c++
 * the std::shared_pointer can be used when multiple ownership
 * has to be taken of dynamically allocated objects and memory managed
 * to use it, include the <memory> header
 * use the std::make_shared<TYPE>() function to allocate an object
 * for the shared pointer type
 *
 * the sample below will verify what is supposed to happen
 * with logging the constructor and destructor calls
 */
#include<iostream>
#include<memory>
class A{
	public:
		A(){
			std::cout<<"A()"<<std::endl;
		};
		~A(){
			std::cout<<"~A()"<<std::endl;
		};
	private:
	protected:
};
int main(int argc,char** argv){
	std::shared_ptr<A> a;
	{
		auto b=std::make_shared<A>();
		{
			auto c=b;
			{
				auto d=c;
				{
					a=d;
				}
			}
		}
	}
	//once a goes out of scope the object initially assigned to b will be deleted
	return 0;
}
