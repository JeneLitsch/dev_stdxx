#pragma once
#include <cstdint>
#include <array>
#include <iostream>
#include <functional>

namespace stx {
	template<typename T, std::size_t N>
	class vectorN {
	public:
		constexpr vectorN() {
			std::fill(std::begin(this->elements), std::end(this->elements), T{});
		}

		constexpr vectorN(const std::array<T, N> & array)
		: elements {array} {}

		constexpr vectorN(T x) {
			std::fill(std::begin(this->elements), std::end(this->elements), x);
		}

		constexpr vectorN(T x1, auto &&... args)
		: elements{x1, static_cast<T>(args)...} {}

		constexpr T & operator[](std::size_t i) {
			return elements[i];
		}

		constexpr const T & operator[](std::size_t i) const {
			return elements[i];
		}
	private:
		std::array<T, N> elements;
	};



	template<typename Op, typename T, std::size_t N>
	constexpr vectorN<T, N> element_wise(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {
		
		vectorN<T, N> vec;
		for(std::size_t i = 0; i < N; ++i) {
			vec[i] = Op{}(l[i], r[i]);
		}
		return vec;
	}


	
	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator+(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {

		return element_wise<std::plus<T>>(l, r);
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator-(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {
			
		return element_wise<std::minus<T>>(l, r);
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator*(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {
			
		return element_wise<std::multiplies<T>>(l, r);
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator/(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {
			
		return element_wise<std::divides<T>>(l, r);
	}



	template<typename Op, typename T, std::size_t N>
	constexpr vectorN<T, N> scalar_operation(
		const vectorN<T, N> & v,
		const T & scalar) {
		vectorN<T, N> vec;
		for(std::size_t i = 0; i < N; ++i) {
			vec[i] = Op{}(v[i], scalar);
		}
		return vec;
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator*(
		const vectorN<T, N> & v,
		const T & scalar) {
		return scalar_operation<std::multiplies<T>>(v, scalar);
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator*(
		const T & scalar,
		const vectorN<T, N> & v) {
		return scalar_operation<std::multiplies<T>>(v, scalar);
	}



	template<typename T, std::size_t N>
	constexpr vectorN<T, N> operator/(
		const vectorN<T, N> & v,
		const T & scalar) {
		return scalar_operation<std::divides<T>>(v, scalar);
	}



	template<typename T, std::size_t N>
	constexpr bool operator==(
		const vectorN<T, N> & l,
		const vectorN<T, N> & r) {
		
		for(std::size_t i = 0; i < N; ++i) {
			if(l[i] != r[i]) return false;
		}
		return true;
	}




	template<typename T, std::size_t N>
	std::ostream & operator<<(std::ostream & out, const vectorN<T, N> & vec) {
		out << "(";
		for(std::size_t i = 0; i < N; ++i) {
			if(i) out << ", ";
			out << vec[i];
		}
		out << ")";
		return out;
	}
}