#include "cphinx/cphinx.hxx"
#include "proto/enumerate.hxx"
#include <array>
#include <vector>

CPHINX_TEST(enumerate_array_index) {
	std::array<int, 5> arr = {1,2,3,4,5};
	int expected_index = 0;
	for(const auto pair : stx::enumerate<int>(arr)) {
		cphinx.assert_equal(pair.index(), expected_index);
		++expected_index;
	}
}



CPHINX_TEST(enumerate_const_array_index) {
	const std::array<int, 5> arr = {1,2,3,4,5};
	int expected_index = 0;
	for(const auto pair : stx::enumerate<int>(arr)) {
		cphinx.assert_equal(pair.index(), expected_index);
		++expected_index;
	}
}



CPHINX_TEST(enumerate_vector_index) {
	std::vector<int> arr = {1,2,3,4,5};
	int expected_index = 0;
	for(const auto pair : stx::enumerate<int>(arr)) {
		cphinx.assert_equal(pair.index(), expected_index);
		++expected_index;
	}
}



CPHINX_TEST(enumerate_const_vector_index) {
	const std::vector<int> arr = {1,2,3,4,5};
	int expected_index = 0;
	for(const auto pair : stx::enumerate<int>(arr)) {
		cphinx.assert_equal(pair.index(), expected_index);
		++expected_index;
	}
}