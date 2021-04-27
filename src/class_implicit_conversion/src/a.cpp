class A{
	A(){};
	int m;
	public:
		A(const int&p):m(p){};
		~A(){};
};
int main(int argc,char*argv[]){
	{A a=42;}
	{A a(42);}
	{A a{42};}
	{auto a=static_cast<A>(42);}
	{A a='.';}
	{A a('.');}
	{A a{'.'};}
	{auto a=static_cast<A>('.');}
}
