#include<cstdlib>
#include<algorithm>
#include<functional>
#include<algorithm>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::cout<<std::distance(a.begin(),a.end())<<std::endl;
	for(int i=0;i<5;++i){
		auto b=std::find(a.begin(),a.end(),i);
		if(b!=a.end()){
			std::cout<<i<<" found at position "<<std::distance(a.begin(),b)<<std::endl;
		}else{
			std::cout<<i<<" not found"<<std::endl;
		}
	}
	return EXIT_SUCCESS;
}
