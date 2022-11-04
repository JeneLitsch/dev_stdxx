#include "cphinx/cphinx.hxx"
#include "proto/enumerate.hxx"
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <deque>
#include <span>
#include <string>



template<typename Index, typename Container>
void enumerate_container_impl(auto & cphinx, Container & container, bool expected_const) {
	Index expected_index = 0;
	auto it = std::begin(container);
	for(auto [i, v] : stx::enumerate<Index>(container)) {
		if constexpr(std::is_const_v<std::remove_reference_t<decltype(v)>>) {
			cphinx.assert_equal(true, expected_const, "Const mismatch");
		}
		else {
			cphinx.assert_equal(false, expected_const, "Const mismatch");
		}
		cphinx.assert_equal(i, expected_index, "Index mismatch");
		cphinx.assert_equal(v, *it, "Value mismatch");
		++expected_index;
		++it;
	}
	cphinx.assert_equal(static_cast<Index>(std::size(container)), expected_index, "Size mismatch");
}



template<typename Index, typename Container>
void enumerate_container(auto & cphinx, Container & container) {
	enumerate_container_impl<Index, Container>(cphinx, container, false);
	enumerate_container_impl<Index, const Container>(cphinx, std::as_const(container), true);
}


template<typename Index, typename T>
void enumerate_container(auto & cphinx, std::span<T> & container) {
	enumerate_container_impl<Index>(cphinx, container, false);
	enumerate_container_impl<Index>(cphinx, std::as_const(container), false);
}


template<typename Index, typename T>
void enumerate_container(auto & cphinx, std::set<T> & container) {
	enumerate_container_impl<Index>(cphinx, container, true);
	enumerate_container_impl<Index>(cphinx, std::as_const(container), true);
}

template<typename Index, typename T>
void enumerate_container(auto & cphinx, std::unordered_set<T> & container) {
	enumerate_container_impl<Index>(cphinx, container, true);
	enumerate_container_impl<Index>(cphinx, std::as_const(container), true);
}



template<typename Index, typename Container>
void enumerate_write(auto & cphinx, Container & container) {
	auto it = std::begin(container);
	for(auto [i, v] : stx::enumerate<Index>(container)) {
		v += v;
		cphinx.assert_equal(v, *it, "Value mismatch");
		++it;
	}
}



CPHINX_TEST(enumerate_c_array) {
	int arr[5] = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_write_c_array) {
	int arr[5] = {1,2,3,4,5};
	enumerate_write<int>(cphinx, arr);
	enumerate_write<unsigned>(cphinx, arr);
	enumerate_write<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_array) {
	std::array<int, 5> arr = {1,2,3,4,5};
	enumerate_container<int>(cphinx, arr);
	enumerate_container<unsigned>(cphinx, arr);
	enumerate_container<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_write_array) {
	std::array<int, 5> arr = {1,2,3,4,5};
	enumerate_write<int>(cphinx, arr);
	enumerate_write<unsigned>(cphinx, arr);
	enumerate_write<std::size_t>(cphinx, arr);
}



CPHINX_TEST(enumerate_vector) {
	std::vector<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_write_vector) {
	std::vector<int> vec = {1,2,3,4,5};
	enumerate_write<int>(cphinx, vec);
	enumerate_write<unsigned>(cphinx, vec);
	enumerate_write<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_set) {
	std::set<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_unordered_set) {
	std::unordered_set<int> vec = {1,2,3,4,5};
	enumerate_container<int>(cphinx, vec);
	enumerate_container<unsigned>(cphinx, vec);
	enumerate_container<std::size_t>(cphinx, vec);
}



CPHINX_TEST(enumerate_map) {
	std::map<int,int> map = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	enumerate_container<int>(cphinx, map);
	enumerate_container<unsigned>(cphinx, map);
	enumerate_container<std::size_t>(cphinx, map);
}



CPHINX_TEST(enumerate_unordered_map) {
	std::unordered_map<int,int> map = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	enumerate_container<int>(cphinx, map);
	enumerate_container<unsigned>(cphinx, map);
	enumerate_container<std::size_t>(cphinx, map);
}



CPHINX_TEST(enumerate_list) {
	std::list<int> list = {1,2,3,4,5};
	enumerate_container<int>(cphinx, list);
	enumerate_container<unsigned>(cphinx, list);
	enumerate_container<std::size_t>(cphinx, list);
}



CPHINX_TEST(enumerate_deque) {
	std::deque<int> deq = {1,2,3,4,5};
	enumerate_container<int>(cphinx, deq);
	enumerate_container<unsigned>(cphinx, deq);
	enumerate_container<std::size_t>(cphinx, deq);
}



CPHINX_TEST(enumerate_span) {
	std::vector<int> vec = {1,2,3,4,5};
	std::span<int> span = vec;
	enumerate_container<int>(cphinx, span);
	enumerate_container<unsigned>(cphinx, span);
	enumerate_container<std::size_t>(cphinx, span);
}



CPHINX_TEST(enumerate_string) {
	std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	enumerate_container<int>(cphinx, str);
	enumerate_container<unsigned>(cphinx, str);
	enumerate_container<std::size_t>(cphinx, str);
}

