#include <iostream>
#include <memory>
#include "proto/bound.hxx"
#include "proto/optref.hxx"
#include "proto/enumerate.hxx"
#include "proto/mandatory.hxx"


void enumerate() {
	std::vector<int> array1 {
		1, 2, 3, 4, 5
	};

	const std::vector<int> array2 {
		1, 2, 3, 4, 5
	};


	const std::array<int, 5> array3 {
		1, 2, 3, 4, 5
	};
	
	for(auto pair : stx::enumerate<int>(array1)) {
		std::cout << pair.index() << " : " << pair.value() << "\n";
		pair.value()++;
	}

	std::cout << "\n";

	for(auto pair : stx::enumerate<int>(array2)) {
		std::cout << pair.index() << " : " << pair.value() << "\n";
	}

	std::cout << "\n";

	for(const auto pair : stx::enumerate(array3)) {
		auto a = pair;
		std::cout << pair.index() << " : " << a.value() << "\n";
	}

	std::cout << "\n";

	for(auto [index, value] : stx::enumerate(array3)) {
		std::cout << index << " : " << *value << "\n";
	}
}



void mandatory() {
	stx::mandatory<int> i = 42;
	stx::mandatory<float> f = static_cast<float>(i);
	stx::mandatory<std::unique_ptr<int>> ptr1 = std::make_unique<int>(4);
	stx::mandatory<std::unique_ptr<int>> ptr2 = std::move(ptr1);
}



int main() {
	enumerate();
}
