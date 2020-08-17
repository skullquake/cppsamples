#include<iostream>
#include<algorithm>
#include<valarray>
#include<iterator>
#include<cstdlib>
int main(void){
	{//process
		std::valarray<int>a{0,1,2,3};
		std::valarray<int>b;
		b=a.apply([](int a){return a=a*2;});
		//std::copy(std::begin(a),std::begin(a),std::ostream_iterator<int>(std::cout," "));//??
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
		for(auto&c:b)
			std::cout<<c<<" ";
		std::cout<<std::endl;
		std::cout<<a.min()<<std::endl;
		std::cout<<a.max()<<std::endl;
	}
	{//right shift
		std::valarray<int>a{1,2,3,4};
		a=a.shift(2);
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
	{//left shift
		std::valarray<int>a{1,2,3,4};
		a=a.shift(-2);
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
	{//circular right shift
		std::valarray<int>a{1,2,3,4};
		a=a.cshift(2);
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
	{//circular left shift
		std::valarray<int>a{1,2,3,4};
		a=a.cshift(-2);
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
	{//swap
		std::valarray<int>a{1,2,3,4};
		std::valarray<int>b{4,3,2,1};
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
		for(auto&c:b)
			std::cout<<c<<" ";
		std::cout<<std::endl;
		a.swap(b);
		for(auto&c:a)
			std::cout<<c<<" ";
		std::cout<<std::endl;
		for(auto&c:b)
			std::cout<<c<<" ";
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
