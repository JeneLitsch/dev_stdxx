#include "proto/bound.hxx"
#include "proto/optref.hxx"
#include "proto/enumerate.hxx"
#include <iostream>


int main() {
	std::vector<int> array1 {
		1, 2, 3, 4, 5
	};

	const std::vector<int> array2 {
		1, 2, 3, 4, 5
	};
	
	for(auto pair : stx::enumerate<int>(array1)) {
		std::cout << pair.index() << " : " << pair.value() << "\n";
		pair.value()++;
	}

	for(auto pair : stx::enumerate<int>(array2)) {
		std::cout << pair.index() << " : " << pair.value() << "\n";
	}

	std::cout << "\n";

	for(const auto pair : stx::enumerate<int>(array1)) {
		auto a = pair;
		std::cout << pair.index() << " : " << a.value() << "\n";
	}
}
