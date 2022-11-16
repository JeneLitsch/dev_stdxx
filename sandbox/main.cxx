#include <vector>
#include <iostream>
#include "proto/matrix.hxx"

int main() {
	stx::matrix<float, 3, 4> m { 
		1,  2,  3,
		4,  5,  6,
		7,  8,  9,
		10, 11, 12,
	};

	stx::matrix<float, 3, 4> m2 { 42 };

	std::cout << m(2, 3) << "\n";
	std::cout << m2(2, 3) << "\n";
}
