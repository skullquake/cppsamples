/*
 * performs a left rotation on a range of elements such that the
 * produces output via output iterator
 */
#include<iostream>
#include<vector>
int main(int argc,char** argv){
	//rotate left
	{
		std::vector<int> a={0,1,2,3,4};
		std::vector<int> b;
		for(auto c:a){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
		std::rotate_copy(a.begin(),a.begin()+1,a.end(),std::back_inserter(b));
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}
	//rotate right 
	{
		std::vector<int> a={0,1,2,3,4};
		std::vector<int> b;
		for(auto c:a){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
		std::rotate_copy(a.begin(),a.begin()+a.size()-1,a.end(),std::back_inserter(b));
		for(auto c:b){
			std::cout<<c<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}
