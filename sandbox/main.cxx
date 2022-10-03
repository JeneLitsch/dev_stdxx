#include "proto/bound.hxx"
#include "proto/optref.hxx"
#include <iostream>

struct S {
	int x;
};


int main() {
	stx::optref<const int> r = std::nullopt;
	int i = 42;

	std::cout << r.value_or(i) << "\n";
	// std::cout << r.value_or(42) << "\n";
}
