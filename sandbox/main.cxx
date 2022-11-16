#include <vector>
#include <iostream>
#include "proto/vectorN.hxx"

int main() {
	stx::vectorN<float, 5> vec1 = {1,2,3,4,5};	
	stx::vectorN<float, 5> vec2 = {2,2,2,2,2};	
	std::cout << "vec1: " << vec1 << "\n";
	std::cout << "vec2: " << vec2 << "\n";
	std::cout << "+:" << vec1 + vec2 << "\n";
	std::cout << "-:" << vec1 - vec2 << "\n";
	std::cout << "*:" << vec1 * vec2 << "\n";
	std::cout << "/:" << vec1 / vec2 << "\n";
}
