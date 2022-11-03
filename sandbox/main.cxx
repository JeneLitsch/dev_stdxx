#include <iostream>
#include <memory>
#include <span>
#include <set>
#include "proto/bound.hxx"
#include "proto/optref.hxx"
#include "proto/enumerate.hxx"
#include "proto/mandatory.hxx"


template<typename T>
bool aaaaa(T & t) {
	auto it = std::begin(t);
	return std::is_const_v<std::remove_reference_t<decltype(*it)>>;
}


auto enumerate_container(auto & cphinx, std::span<int> & container) {
	{	
		std::size_t expected_index = 0;
		auto it = std::begin(container);
		for(auto [i, v] : stx::enumerate<std::size_t>(container)) {
			cphinx.assert_equal(i, expected_index, "Index mismatch");
			cphinx.assert_equal(v, *it, "Value mismatch");
			cphinx.assert_true(!std::is_const_v<std::remove_reference_t<decltype(*v)>>, "value must NOT be const");
			++expected_index;
			++it;
		}
		cphinx.assert_equal(static_cast<std::size_t>(std::size(container)), expected_index, "Size mismatch");
	}
}



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
	
	for(auto [index, value] : stx::enumerate<int>(array1)) {
		std::cout << index << " : " << value << "\n";
		value++;
	// std::is_const_v<std::remove_reference_t<decltype(pair.value())>>;
	}

	std::cout << "\n";

	for(auto [index, value] : stx::enumerate<int>(array2)) {
		std::cout << index << " : " << value << "\n";
	}

	std::cout << "\n";

	for(auto [index, value] : stx::enumerate(array3)) {
		std::cout << index << " : " << value << "\n";
	}

	std::cout << "\n";

	// std::set<int> s { 1, 2, 3, 4, 5 };
	std::vector<int> vec = {1,2,3,4,5};
	std::span<int> s = vec;
	auto a = std::begin(s);
	auto x = stx::enumerate(s);
	auto it = std::begin(x);
	auto [i,v] = *it;
	for(auto [index, value] : stx::enumerate(s)) {
		std::cout << index << " : " << value << "\n";
	}

	decltype(auto) b = aaaaa(s);
}



void mandatory() {
	stx::mandatory<int> i = 42;
	stx::mandatory<float> f = static_cast<float>(i);
	stx::mandatory<std::unique_ptr<int>> ptr1 = std::make_unique<int>(4);
	stx::mandatory<std::unique_ptr<int>> ptr2 = std::move(ptr1);
}



int main() {
	// enumerate();
	std::vector<int> vec = {1,2,3,4,5};
	std::span<int> s = vec;
	std::cout << aaaaa(s) << "\n";
}
