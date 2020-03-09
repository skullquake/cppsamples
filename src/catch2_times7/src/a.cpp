#include<iostream>
#define CATCH_CONFIG_MAIN //tell main(), only do this for one source file
#include<catch2/catch.hpp>
#include<vector>
#include<algorithm>
std::vector<int> times7(std::vector<int> const& numbers){
	auto results=std::vector<int>{};
	std::transform(
		std::begin(numbers),
		std::end(numbers),
		std::back_inserter(results),
		[](int n){
			return 7*n;
		}
	);
	return results;
}
TEST_CASE(
	"times7 computed",
	"[times7]"
){
	{
		auto const inputs=std::vector<int>{3,4,7};
		auto const results=times7(inputs);
		auto const expected={21,28,49};
		REQUIRE(
			std::equal(
				std::begin(results),
				std::end(results),
				std::begin(expected),
				std::end(expected)
			)
		);
	}
	{
		auto const inputs=std::vector<int>{4,5,8};
		auto const results=times7(inputs);
		auto const expected={28,35,56};
		REQUIRE(
			std::equal(
				std::begin(results),
				std::end(results),
				std::begin(expected),
				std::end(expected)
			)
		);
	}
}
