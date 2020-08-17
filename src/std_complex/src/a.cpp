#include<iostream>
#include<complex>
#include<sstream>
#include<cstdlib>
int main(void){
	std::stringstream ss;
	//the specializations of std::complex<float>,std::complex<double>,and std::complex<long double. are LiteralTypes for representing and manipulating complex numbers. The effect of instantiating the template complex for any other type is unspecified
	std::complex<double>a(2,3);		//constructor
	ss<<a;					//serializes complex number
	ss>>a;					//deserializes complex number
	std::cout<<a.real()<<std::endl;		//access the real part of the complex number
	std::cout<<a.imag()<<std::endl;		//access the imaginary part of the complex number
	std::cout<<a+a<<std::endl;		//+ operator
	std::cout<<a-a<<std::endl;		//- operator
	std::cout<<a*a<<std::endl;		//* operator
	std::cout<<a/a<<std::endl;		/// operator
	std::cout<<a+4.2<<std::endl;		//+ operator
	std::cout<<a-4.2<<std::endl;		//- operator
	std::cout<<a*4.2<<std::endl;		//* operator
	std::cout<<a/4.2<<std::endl;		/// operator
	std::cout<<4.2+a<<std::endl;		//+ operator
	std::cout<<4.2-a<<std::endl;		//- operator
	std::cout<<4.2*a<<std::endl;		//* operator
	std::cout<<4.2/a<<std::endl;		/// operator
	a=a;					//assignment
	a+=a;					//+= operator
	a-=a;					//-= operator
	a*=a;					//*= operator
	a/=a;					///= operator
	//todo:rest of arithmetic operators...
	std::cout<<std::exp(a)<<std::endl;	//complex base e exponential
	std::cout<<std::log(a)<<std::endl;	//complex naturla logarithm with the branch cuts along the negative real axis
	std::cout<<std::log10(a)<<std::endl;	//complex common logarithm with the branch cuts along the negative real axis
	std::cout<<std::pow(a,2)<<std::endl;	//complex power, one or both arguments may be a complex number
	std::cout<<std::pow(a,a)<<std::endl;	//complex power, one or both arguments may be a complex number
	std::cout<<std::sqrt(a)<<std::endl;	//complex square root in the range of the right half-plane
	std::cout<<std::sin(a)<<std::endl;	//computes sine of a complex number
	std::cout<<std::cos(a)<<std::endl;	//computes cosine of a complex number
	std::cout<<std::tan(a)<<std::endl;	//computes tangent of a complex number
	std::cout<<std::asin(a)<<std::endl;	//computes arc sine of a complex number
	std::cout<<std::acos(a)<<std::endl;	//computes arc cosine of a complex number
	std::cout<<std::atan(a)<<std::endl;	//computes arc tangent of a complex number
	std::cout<<std::sinh(a)<<std::endl;	//computes hyperbolic sine of a complex number
	std::cout<<std::cosh(a)<<std::endl;	//computes hyperbolic cosine of a complex number
	std::cout<<std::tanh(a)<<std::endl;	//computes hyperbolic tangent of a complex number
	std::cout<<std::asinh(a)<<std::endl;	//computes area hyperbolic sine of a complex number
	std::cout<<std::acosh(a)<<std::endl;	//computes area hyperbolic cosine of a complex number
	std::cout<<std::atanh(a)<<std::endl;	//computes are hyperbolic tangent of a complex number
	std::cout<<std::real(a)<<std::endl;	//access the real part of the complex number
	std::cout<<std::imag(a)<<std::endl;	//access the imaginary part of the complex number
	std::cout<<std::arg(a)<<std::endl;	//returns the phase angle
	std::cout<<std::norm(a)<<std::endl;	//returns the squared magnitude
	std::cout<<std::conj(a)<<std::endl;	//returns the complex conjugate
	std::cout<<std::proj(a)<<std::endl;	//returns the projection onto the Riemann sphere
	std::cout<<std::polar(a)<<std::endl;	//constructs a complex number from magnitude and phase angle
	std::cout<<std::polar(1,2)<<std::endl;	//constructs a complex number from magnitude and phase angle
	std::cout<<std::exp(a)<<std::endl;	//complex base e exponential
	std::cout<<reinterpret_cast<double(&)[2]>(a)[0]<<std::endl;//for any object z of type complex<T>, reinterpret_caswt<T()&[2]>(z)[0] is the real part of z
	std::cout<<reinterpret_cast<double(&)[2]>(a)[1]<<std::endl;//for any object z of type complex<T>, reinterpret_caswt<T()&[2]>(z)[1] is the imaginary part of z
	std::cout<<std::boolalpha<<(a!=a)<<std::endl;//a.real()!=a.real()||a.imag()!=a.imag()
	std::cout<<std::boolalpha<<(a==a)<<std::endl;//a.real()==a.real()&&a.imag()==a.imag()
	std::cout<<std::boolalpha<<(a!=4.2)<<std::endl;//a.real()!=4.2
	std::cout<<std::boolalpha<<(a==4.2)<<std::endl;//a.real()==4.2
	std::cout<<std::boolalpha<<(4.2!=a)<<std::endl;//4.2!=a.real()
	std::cout<<std::boolalpha<<(4.2==a)<<std::endl;//4.2==a.real()
	std::complex<double>buf[4];
	for(size_t i=0;i<sizeof(buf)/sizeof(*buf);++i){
		buf[i].real(static_cast<double>(i)/10);
		buf[i].imag(static_cast<double>(i)/10*2);
	}
	for(size_t i=0;i<sizeof(buf)/sizeof(*buf);++i){
		std::cout<<
			(reinterpret_cast<double*>(buf)[2*i])<<
			":"
			<<(reinterpret_cast<double*>(buf)[2*i+1])
			<<std::endl
		;				//For any pointer to an element of array of complex<T> named p and any valid array index i, reinterpret_cast<T*>(p)[2*i] is the real part of the complex number p[i], and reinterpret_cast<T*>(p)[2*i+1] is the imaginary part of the complex number p[i]
	}
	{//read process example
		std::istringstream iss(
R"(
(0.1,0.2)
(0.3,0.4)
(0.5,0.6)
(0.7,0.8)
(0.9,1.0)
(1.1,1.2)
)"
		);
		size_t idx=0;
		while(iss.peek()!=EOF){
			std::complex<double>c0;
			std::complex<double>c1;
			iss>>c0;
			if(!iss){
				std::cerr<<"error:failed to read"<<std::endl;
				break;
			}
			iss>>c1;
			if(!iss){
				std::cerr<<"error:failed to read"<<std::endl;
				break;
			}
			iss.ignore(std::numeric_limits<int>::max(),'\n');
			std::cout<<idx<<":c0:    "<<c0<<std::endl;
			std::cout<<idx<<":c1:    "<<c1<<std::endl;
			std::cout<<idx<<":c0+c1: "<<c0+c1<<std::endl;
			std::cout<<idx<<":c0-c1: "<<c0-c1<<std::endl;
			std::cout<<idx<<":c0*c1: "<<c0*c1<<std::endl;
			std::cout<<idx<<":c0/c1: "<<c0/c1<<std::endl;
			std::cout<<idx<<":c0^c1: "<<std::pow(c0,c1)<<std::endl;
			++idx;
		}
	}
	return EXIT_SUCCESS;
}
