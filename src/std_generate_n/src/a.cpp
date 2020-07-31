#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iterator>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a;
	std::generate_n(
		std::back_inserter(a),
		8,
		[](){class{
			public:
				int operator()(){return acc++;}
			private:
				int acc=0;
		}_;return _;}()//how to make anonymous class instance???
	);
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	a.clear();
	std::generate_n(
		std::back_inserter(a),
		8,
		[](){class{
			public:
				int operator()(){return acc+=acc;}
			private:
				int acc=1;
		}_;return _;}()//how to make anonymous class instance???
	);
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	a.clear();
	std::generate_n(
		std::back_inserter(a),
		8,
		[](){class{
			public:
				int operator()(){
					acc0+=acc0;
					acc1+=acc1;
					acc2+=acc2;
					acc3+=acc3;
					return acc0+acc1+acc2+acc3;
				}
			private:
				int acc0=1;
				int acc1=2;
				int acc2=3;
				int acc3=4;
		}_;return _;}()//how to make anonymous class instance???
	);
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	return EXIT_SUCCESS;
}
