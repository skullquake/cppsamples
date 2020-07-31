/*
 * std::find finds the element in the given range of numbers
 * returns an iterator to the first element in the range [first,last) that compares equal to val
 * if no element is found, returns last
 */
#include<iostream>
#include<vector>
#include<algorithm>
int main(int argc,char** argv){
	std::vector v={0,1,2,3,2,1,0};
	std::vector<int>::iterator i;
	{
		i=std::find(v.begin(),v.end(),1);
		if(i!=v.end()){
			std::cout<<"found["<<(i-v.begin())<<"]"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	{
		i=std::find(v.begin(),v.end(),32);
		if(i!=v.end()){
			std::cout<<"found["<<(i-v.begin())<<"]"<<std::endl;
		}else{
			std::cout<<"not found"<<std::endl;
		}
	}
	return 0;
}
