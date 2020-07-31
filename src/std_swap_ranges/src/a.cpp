#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iterator>
#include<iostream>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b{3,2,1,0};
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::copy(b.begin(),b.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::swap_ranges(a.begin(),a.end(),b.begin());
	std::copy(a.begin(),a.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::copy(b.begin(),b.end(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	return EXIT_SUCCESS;
}
