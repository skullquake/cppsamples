#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<tuple>
#include<cstdlib>
int main(void){
	std::istringstream iss(R"(0 0 0
0 0 1
0 1 0
0 1 x
1 0 0
1 y 1
1 1 0 1 2 1
z 1 1
)");
	std::vector<std::tuple<bool,int,int,int>>vt;
	std::tuple<int,int,int>t;
	int x,y,z;
	size_t idx=0;
	std::string line;
	while(std::getline(iss,line)){
		std::istringstream issline(line);
		if(
			(!(issline>>x).fail())&&
			(!(issline>>y).fail())&&
			(!(issline>>z).fail())
		){
			if(issline.eof()){
				vt.push_back(std::make_tuple(false,x,y,z));
			}else{
				std::cout<<"error:line "<<idx<<":superflous vals:"<<line<<std::endl;
			}
		}else{
			vt.push_back(std::make_tuple(true,0,0,0));
			std::cout<<"error:line "<<idx<<":failed to parse:"<<line<<std::endl;
		}
		++idx;
	}
	if(iss.eof()){
		idx=0;
		for(const auto&t:vt){
			std::cout<<'['<<std::setw(3)<<idx<<']';
			if(!std::get<0>(t)){
				std::cout<<'['<<std::get<0>(t)<<','<<std::get<1>(t)<<','<<std::get<2>(t)<<','<<std::get<3>(t)<<']'<<std::endl;
			}else{
				std::cout<<" err"<<std::endl;

			}
			++idx;
		}
	}else{
		std::cout<<"error:line "<<idx<<std::endl;
	}
	return EXIT_SUCCESS;
}
