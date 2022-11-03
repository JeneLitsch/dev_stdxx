#include "cphinx/cphinx.hxx"
#include "proto/enumerate.hxx"
#include <array>
#include <vector>
#include <set>
#include <list>
#include <deque>

template<typename Index, typename Container>
void enumerate_container(auto & cphinx, Container & container) {
	{
		Index expected_index = 0;
		auto it = std::begin(container);
		for(const auto pair : stx::enumerate<Index>(container)) {
			cphinx.assert_equal(pair.index(), expected_index, "Index mismatch");
			cphinx.assert_equal(pair.value(), *it, "Value mismatch");
			++expected_index;
			++it;
		}
		cphinx.assert_equal(static_cast<Index>(std::size(container)), expected_index, "Size mismatch");
	}

	{
		Index expected_index = 0;
		auto it = std::begin(container);
		for(auto [i, v] : stx::enumerate<Index>(container)) {
			cphinx.assert_equal(i, expected_index, "Index mismatch");
			cphinx.assert_equal(*v, *it, "Value mismatch");
			++expected_index;
			++it;
		}
		cphinx.assert_equal(static_cast<Index>(std::size(container)), expected_index, "Size mismatch");
	}
}



CPHINX_TEST(enumerate_c_array) {
	int arr[5] = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_const_c_array) {
	const int arr[5] = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}




CPHINX_TEST(enumerate_array) {
	std::array<int, 5> arr = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_const_array) {
	const std::array<int, 5> arr = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_vector) {
	std::vector<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_const_vector) {
	const std::vector<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_set) {
	std::set<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_const_set) {
	const std::set<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}




CPHINX_TEST(enumerate_list) {
	std::list<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_const_list) {
	const std::set<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_deque) {
	std::deque<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_const_deque) {
	const std::deque<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}