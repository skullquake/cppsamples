/*
 * copies from source to target [first,last), in reverse, with relative order maintained
 * this requires that the target range be sized appropriately
 */
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>
#include<iterator>
int main(void){
	std::vector<int>a{0,1,2,3};
	std::vector<int>b(a.size());
	std::copy(a.cbegin(),a.cend(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::copy(b.cbegin(),b.cend(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	std::copy_backward(a.begin(),a.end(),b.end());
	std::copy(b.cbegin(),b.cend(),std::ostream_iterator<int>(std::cout," "));std::cout<<std::endl;
	return EXIT_SUCCESS;
}
