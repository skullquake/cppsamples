#include <iostream>
#include <range/v3/all.hpp>
int main(int argc,char** argv){
    using namespace ranges;
	std::cout<<
		ranges::accumulate(
			 ranges::views::ints(1,unreachable)
			|views::transform([](int i){
				return i*i;
			})
			|views::take(10),
			0
		)
		<<std::endl;
}
///[accumulate_ints]
