#include<iostream>
#include<string>
#include<initializer_list>
#include<vector>
class Point{
        public:
                Point(std::initializer_list<int> il){
                        mx=il.size()>0?il.begin()[0]:0;
                        my=il.size()>1?il.begin()[1]:0;
                        mz=il.size()>2?il.begin()[2]:0;
                };
		void print(){
			std::cout<<"["<<mx<<","<<my<<","<<mz<<"]"<<std::endl;
		}
        private:
                int mx;
                int my;
                int mz;
};
class List{
        public:
                List(std::initializer_list<std::string> il):mdata(il){
                };
		void print(){
			for(auto itm:mdata){
				std::cout<<itm<<std::endl;
			}
		}
        private:
                std::vector<std::string> mdata;
};

template<class T>
void fn(std::initializer_list<T> const& list){
	for(auto elem:list){
		std::cout<<elem<<std::endl;
	}
}
int main(int argc,char** argv){
	fn({1,2});
	{
		Point p0({});
		Point p1({1});
		Point p2({1,2});
		Point p3({1,2,3});
		p0.print();
		p1.print();
		p2.print();
		p3.print();
	}
	List l({"foo","bar","baz"});
	l.print();
	return 0;
}
