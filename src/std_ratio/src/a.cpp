#include<iostream>
#include<ratio>
#include<cstdlib>
int main(void){
	using do1=std::ratio<1,1>;
	using re1=std::ratio<9,8>;
	using mi1=std::ratio<5,4>;
	using fa1=std::ratio<4,3>;
	using so1=std::ratio<3,2>;
	using la1=std::ratio_multiply<fa1,mi1>;
	using ti1=std::ratio_multiply<so1,mi1>;
	using do2=std::ratio<2,1>;
	using ra1=std::ratio_divide<fa1,mi1>;
	using di1=std::ratio_divide<std::ratio_multiply<la1,mi1>,std::ratio<1,2>>;
	using ma1=std::ratio_divide<so1,mi1>;
	using ri1=std::ratio_divide<std::ratio_multiply<ti1,mi1>,std::ratio<1,2>>;
	using fi1=std::ratio_divide<std::ratio_multiply<ti1,mi1>,std::ratio<1,2>>;
	using ta1=std::ratio_divide<do2,re1>;
	using sa1=std::ratio_divide<ta1,mi1>;
	using lo1=std::ratio_divide<do2,mi1>;
	using si1=std::ratio_multiply<mi1,mi1>;
	using li1=std::ratio_multiply<fi1,mi1>;
	std::cout<<"do1:"<<do1::num<<"/"<<do1::den<<std::endl;
	std::cout<<"di1:"<<ra1::num<<"/"<<ra1::den<<std::endl;
	std::cout<<"ra1:"<<di1::num<<"/"<<di1::den<<std::endl;
	std::cout<<"re1:"<<re1::num<<"/"<<re1::den<<std::endl;
	std::cout<<"ma1:"<<ma1::num<<"/"<<ma1::den<<std::endl;
	std::cout<<"ri1:"<<ri1::num<<"/"<<ri1::den<<std::endl;
	std::cout<<"mi1:"<<mi1::num<<"/"<<mi1::den<<std::endl;
	std::cout<<"fa1:"<<fa1::num<<"/"<<fa1::den<<std::endl;
	std::cout<<"sa1:"<<sa1::num<<"/"<<sa1::den<<std::endl;
	std::cout<<"fi1:"<<fi1::num<<"/"<<fi1::den<<std::endl;
	std::cout<<"so1:"<<so1::num<<"/"<<so1::den<<std::endl;
	std::cout<<"lo1:"<<lo1::num<<"/"<<lo1::den<<std::endl;
	std::cout<<"si1:"<<si1::num<<"/"<<si1::den<<std::endl;
	std::cout<<"la1:"<<la1::num<<"/"<<la1::den<<std::endl;
	std::cout<<"ti1:"<<ti1::num<<"/"<<ti1::den<<std::endl;
	std::cout<<"li1:"<<li1::num<<"/"<<li1::den<<std::endl;
	std::cout<<"do1:"<<do2::num<<"/"<<do1::den<<std::endl;
	return EXIT_SUCCESS;
}
