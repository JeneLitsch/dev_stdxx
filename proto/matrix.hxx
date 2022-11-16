#pragma once
#include <array>

namespace stx {
	template<typename T, std::size_t N, std::size_t M>
	class matrix {
	public:
		matrix(T x = T{}) {
			for(std::size_t i = 0; i < N * M; ++i) {
				this->elements[i] = x;
			}
		}

		matrix(T x, auto &&... args) 
		: elements {x, static_cast<T>(args)...} {
			static_assert(sizeof...(args) + 1 == M*N, "Arguments do not match matrix size");
		}

		T & operator()(std::size_t n, std::size_t m) {
			return this->elements[m * N + n];
		}
	private:
		std::array<T, N * M> elements;
	};
}