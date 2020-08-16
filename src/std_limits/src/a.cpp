#include<iostream>
#include<cstdlib>
#include<cstdlib>
int main(void){
	std::cout<<"min: unsigned short:      "<<std::numeric_limits<unsigned short>::min()<<std::endl;
	std::cout<<"max: unsigned short:      "<<std::numeric_limits<unsigned short>::max()<<std::endl;
	std::cout<<"min: unsigned int:        "<<std::numeric_limits<unsigned int>::min()<<std::endl;
	std::cout<<"max: unsigned int:        "<<std::numeric_limits<unsigned int>::max()<<std::endl;
	std::cout<<"min: unsigned long:       "<<std::numeric_limits<unsigned long>::min()<<std::endl;
	std::cout<<"max: unsigned long:       "<<std::numeric_limits<unsigned long>::max()<<std::endl;
	std::cout<<"min: unsigned long long:  "<<std::numeric_limits<unsigned long long>::min()<<std::endl;
	std::cout<<"max: unsigned long long : "<<std::numeric_limits<unsigned long long>::max()<<std::endl;
	std::cout<<"min: short:               "<<std::numeric_limits<short>::min()<<std::endl;
	std::cout<<"max: short:               "<<std::numeric_limits<short>::max()<<std::endl;
	std::cout<<"min: int:                 "<<std::numeric_limits<int>::min()<<std::endl;
	std::cout<<"max: int:                 "<<std::numeric_limits<int>::max()<<std::endl;
	std::cout<<"min: long:                "<<std::numeric_limits<long>::min()<<std::endl;
	std::cout<<"max: long:                "<<std::numeric_limits<long>::max()<<std::endl;
	std::cout<<"min: long long:           "<<std::numeric_limits<long long>::min()<<std::endl;
	std::cout<<"max: long long:           "<<std::numeric_limits<long long>::max()<<std::endl;
	std::cout<<"max: float:               "<<std::numeric_limits<float>::max()<<std::endl;
	std::cout<<"min: float:               "<<std::numeric_limits<float>::min()<<std::endl;
	std::cout<<"max: double:              "<<std::numeric_limits<double>::max()<<std::endl;
	std::cout<<"min: double               "<<std::numeric_limits<double>::min()<<std::endl;
	std::cout<<"max: long double:         "<<std::numeric_limits<long double>::max()<<std::endl;
	std::cout<<"min: long double:         "<<std::numeric_limits<long double>::min()<<std::endl;
	return 0;
}
