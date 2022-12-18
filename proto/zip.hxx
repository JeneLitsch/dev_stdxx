#pragma once
#include <vector>
#include <array>
#include <tuple>

namespace stx::fx {
	// Returns the size of the smallest collection
	std::size_t min_size(auto && ... collections) {
		if constexpr (sizeof...(collections) == 0) return 0;
		const auto sizes = std::to_array({(std::size(collections))...});
		const auto size = std::min_element(std::begin(sizes), std::end(sizes));
		return *size;
	}



	template<typename ... Ts>
	std::vector<std::tuple<Ts...>> zip(const std::vector<Ts> & ... vectors) {
		std::vector<std::tuple<Ts...>> results;
		const std::size_t size = min_size(vectors...);
		for(std::size_t i = 0; i < size; ++i) {
			results.push_back(std::make_tuple((vectors[i])...));
		}
		return results;
	}



	template<typename ... Ts>
	std::vector<std::tuple<Ts...>> zip_mv(std::vector<Ts> && ... vectors) {
		std::vector<std::tuple<Ts...>> results;
		const std::size_t size = min_size(vectors...);
		for(std::size_t i = 0; i < size; ++i) {
			results.push_back(std::make_tuple((std::move(vectors[i]))...));
		}
		return results;
	}



	template<typename ... Ts>
	std::tuple<std::vector<Ts>...> unzip(const std::vector<std::tuple<Ts...>> & vec) {
		std::tuple<std::vector<Ts>...> results;
		for(const auto & at : vec) {
			std::apply([&] (auto & ... vecs) {
				std::apply([&] (auto & ... elems) { 
					((vecs.push_back(elems)),...);
				}, at);
			}, results);
		}
		return results;
	}
}