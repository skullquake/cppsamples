///[comprehension_conversion]
// Use a range comprehension (views::for_each) to construct a custom range, and
// then convert it to a std::vector.
#include<iostream>
#include<vector>
#include<range/v3/range/conversion.hpp>
#include<range/v3/view/for_each.hpp>
#include<range/v3/view/iota.hpp>
#include<range/v3/view/repeat_n.hpp>
int main(int argc,char** argv){
	auto vi=ranges::views::for_each(
		ranges::views::ints(1,6),
		[](int i){
			return ranges::yield_from(ranges::views::repeat_n(i,i));
		}
	)|
	ranges::to<std::vector>();
	std::cout<<ranges::views::all(vi)<<'\n';
	return 0;
}
