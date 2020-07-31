#include<cstdlib>
#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::replace(a.begin(),a.end(),1,42);
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	return EXIT_SUCCESS;
}
