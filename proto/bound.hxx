#pragma once
#include <algorithm>

namespace stx {
	namespace internal {
		template<typename T>
		constexpr T min(T a, T b) {
			return a < b ? a : b;
		}

		template<typename T, typename ...Ts>
		constexpr T min(T a, Ts... rest) {
			return min(a, min(rest...));
		}

		template<typename T>
		constexpr T max(T a, T b) {
			return a > b ? a : b;
		}

		template<typename T, typename ...Ts>
		constexpr T max(T a, Ts... rest) {
			return max(a, max(rest...));
		}
	}

	template<typename T, T MIN, T MAX>
	class bound {
	public:
		bound(T value) : value { std::clamp<T>(value, MIN, MAX) } {}

		constexpr T min() const {
			return MIN;
		}

		constexpr T max() const {
			return MAX;
		}

		constexpr T operator *() const {
			return this->value;
		}

	private:
		T value;
	};



	template<typename T, T MIN_L, T MAX_L, T MIN_R, T MAX_R>
	auto operator+(
		const bound<T, MIN_L, MAX_L> & l,
		const bound<T, MIN_R, MAX_R> & r) {
		return bound<T, MIN_L + MIN_R, MAX_L + MAX_R>{
			*l + *r
		};
	}



	template<typename T, T MIN_L, T MAX_L, T MIN_R, T MAX_R>
	auto operator-(
		const bound<T, MIN_L, MAX_L> & l,
		const bound<T, MIN_R, MAX_R> & r) {
		return bound<T, MIN_L - MAX_R, MAX_L - MIN_R>{
			*l - *r
		};
	}
	


	template<typename T, T MIN_L, T MAX_L, T MIN_R, T MAX_R>
	auto operator*(
		const bound<T, MIN_L, MAX_L> & l,
		const bound<T, MIN_R, MAX_R> & r) {
		
		static constexpr T a = MIN_L * MIN_R;
		static constexpr T b = MAX_L * MAX_R;
		static constexpr T c = MAX_L * MIN_R;
		static constexpr T d = MIN_L * MAX_R;
		
		static constexpr T min = internal::min(a, b, c, d);
		static constexpr T max = internal::max(a, b, c, d);

		return bound<T, min, max>{*l * *r};
	}




	template<typename T, T MIN_L, T MAX_L, T MIN_R, T MAX_R>
	auto operator/(
		const bound<T, MIN_L, MAX_L> & l,
		const bound<T, MIN_R, MAX_R> & r) {
		
		static constexpr T a = MIN_L / MIN_R;
		static constexpr T b = MAX_L / MAX_R;
		static constexpr T c = MAX_L / MIN_R;
		static constexpr T d = MIN_L / MAX_R;
		
		static constexpr T min = internal::min(a, b, c, d);
		static constexpr T max = internal::max(a, b, c, d);

		return bound<T, min, max>{*l / *r};
	}



	template<typename T, T MIN_L, T MAX_L, T MIN_R, T MAX_R>
	auto operator%(
		const bound<T, MIN_L, MAX_L> & l,
		const bound<T, MIN_R, MAX_R> & r) {

		return bound<T, MIN_R, MAX_R>{*l % *r};
	}
}