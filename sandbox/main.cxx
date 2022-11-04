#include <vector>
#include <iostream>
#include "proto/enumerate.hxx"

int main() {
	std::vector<int> arr = {10,20,30,40,50};

	for(const auto [i, v] : stx::enumerate(arr)) {
		std::cout << i << ") " << v << "\n";
	}
}
