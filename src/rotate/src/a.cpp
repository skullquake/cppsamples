/*
 * performs a left rotation on a range of elements such that the
 * middle element in range [first,last) becomes the new first element
 */
#include<iostream>
#include<vector>
int main(int argc,char** argv){
	//rotate left
	{
		std::vector<int> a={0,1,2,3,4};
		for(auto b:a){
			std::cout<<b<<" ";
		}
		std::cout<<std::endl;
		std::rotate(a.begin(),a.begin()+1,a.end());
		for(auto b:a){
			std::cout<<b<<" ";
		}
		std::cout<<std::endl;
	}
	//rotate right 
	{
		std::vector<int> a={0,1,2,3,4};
		for(auto b:a){
			std::cout<<b<<" ";
		}
		std::cout<<std::endl;
		std::rotate(a.begin(),a.begin()+a.size()-1,a.end());
		for(auto b:a){
			std::cout<<b<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}
