#include <vector>
#include <iostream>
#include "proto/enumerate.hxx"
#include "proto/zip.hxx"

int main() {
	std::vector<int> vec_a = {1,2,3};
	std::vector<float> vec_b = {10,20,30,40};
	const auto zipped = stx::fx::zip(vec_a, vec_b);
	const auto [vec_a2, vec_b2] = stx::fx::unzip(zipped);

	for(const auto & [a, b] : zipped) {
		std::cout << a << ", " << b << "\n";
	}

	for(const auto & x : vec_a2) {
		std::cout << x  << "\n";
	}

	for(const auto & x : vec_b2) {
		std::cout << x  << "\n";
	}
}
