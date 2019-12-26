/*
 * c-style arrays can be used in c++
 */
#include<iostream>
int main(int argc,char** argv){
	int a[4];;
	int b[4]={};
	int c[4]={0};
	int d[]={0,1,2,3};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		std::cout<<a[i]<<std::endl;;
	}
	for(int i=0;i<sizeof(b)/sizeof(b[0]);i++){
		std::cout<<b[i]<<std::endl;;
	}
	for(int i=0;i<sizeof(c)/sizeof(c[0]);i++){
		std::cout<<c[i]<<std::endl;;
	}
	for(int i=0;i<sizeof(d)/sizeof(d[0]);i++){
		std::cout<<d[i]<<std::endl;;
	}
	//-std=c++17 provides std::size()
	for(int i=0;i<std::size(a);i++){
		std::cout<<a[i]<<std::endl;;
	}
	for(int i=0;i<std::size(b);i++){
		std::cout<<b[i]<<std::endl;;
	}
	for(int i=0;i<std::size(c);i++){
		std::cout<<c[i]<<std::endl;;
	}
	for(int i=0;i<std::size(d);i++){
		std::cout<<d[i]<<std::endl;;
	}
	//multi dimensional
	int e[2][2];
	int f[2][2]={};
	int g[][2]={{0,1},{2,3}};
	int h[2][2]={{0,1},{2,3}};
	for(int i=0;i<sizeof(e)/sizeof(e[0]);i++){
		for(int j=0;j<sizeof(e[0])/sizeof(e[0][0]);j++){
			std::cout<<e[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<sizeof(f)/sizeof(f[0]);i++){
		for(int j=0;j<sizeof(f[0])/sizeof(f[0][0]);j++){
			std::cout<<f[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<sizeof(g)/sizeof(g[0]);i++){
		for(int j=0;j<sizeof(g[0])/sizeof(g[0][0]);j++){
			std::cout<<g[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<sizeof(h)/sizeof(h[0]);i++){
		for(int j=0;j<sizeof(h[0])/sizeof(h[0][0]);j++){
			std::cout<<h[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	//-std=c++17 provides std::size()
	for(int i=0;i<std::size(e);i++){
		for(int j=0;j<std::size(e[0]);j++){
			std::cout<<e[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<std::size(f);i++){
		for(int j=0;j<std::size(f[0]);j++){
			std::cout<<f[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<std::size(g);i++){
		for(int j=0;j<std::size(g[0]);j++){
			std::cout<<g[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<std::size(h);i++){
		for(int j=0;j<std::size(h[0]);j++){
			std::cout<<h[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	return 0;
}
