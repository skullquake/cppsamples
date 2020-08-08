#include<iostream>
#include<iomanip>
#include<chrono>
#include<ctime>
/*
  def jul(p,q,r):
    '''
    The Julian Day Number (JDN) of the input minus the JDN of January 7, 1970,
    the first new moon after January 1, 1970.
    '''
    t=q<3
    y=p-2000-t  # -2000 years to push day 0 to January 1, 2000
    return r+(153*(q+12*t-3)+2)//5+365*y+y//4-y//100+y//400+11010
    # +11010 days to push day 0 to January 7, 1970
*/
int main(void){
	std::chrono::system_clock::time_point now=std::chrono::system_clock::now();
	time_t tt=std::chrono::system_clock::to_time_t(now);
	tm utc_tm=*gmtime(&tt);
	tm local_tm=*localtime(&tt);
	int y=local_tm.tm_year+1900;
	int m=local_tm.tm_mon+1;
	int d=local_tm.tm_mday;
	std::cout<<y<<std::endl;
	std::cout<<m<<std::endl;
	std::cout<<d<<std::endl;
	{
						std::cout<<"y:  "<<y<<std::endl;
						std::cout<<"m:  "<<m<<std::endl;
						std::cout<<"d:  "<<d<<std::endl;
		int a=y/100;			std::cout<<"a:  "<<a<<std::endl;
		int b=a/4;			std::cout<<"b:  "<<b<<std::endl;
		int c=2-a+b;			std::cout<<"c:  "<<c<<std::endl;
		int e=365.25*(y+4716);		std::cout<<"e:  "<<e<<std::endl;
		int f=30.6001*(m+1);		std::cout<<"f:  "<<f<<std::endl;
		double jd=c+d+e+f-1524.5;	std::cout<<std::fixed<<"jd: "<<jd<<std::endl;
		double dsn=jd-2451549.5;	std::cout<<std::fixed<<"dsn:"<<dsn<<std::endl;
		double nms=dsn/29.53;		std::cout<<std::fixed<<"nms:"<<nms<<std::endl;
		double nmf=nms/29.53;		std::cout<<std::fixed<<"nmf:"<<nmf<<std::endl;
	}
	return EXIT_SUCCESS;
}
