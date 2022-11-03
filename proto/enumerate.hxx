#pragma once
#include <utility>
#include <concepts>

namespace stx {

	template<typename Index, typename Value>
	struct enumerate_pair {
	public:
		enumerate_pair(Index i, Value * v)
		: i {i}, v{v} {}

		Index index() const {
			return this->i;
		}



		Value & value() {
			return *this->v;
		}


		
		const Value & value() const {
			return *this->v;
		}


	template<std::size_t INDEX>
	auto & get() {
		if constexpr (INDEX == 0) return i;
		if constexpr (INDEX == 1) return v;
	}

	template<std::size_t INDEX>
	auto & get() const {
		if constexpr (INDEX == 0) return i;
		if constexpr (INDEX == 1) return v;
	}

	private:
		Index i;
		Value * v;
	};
}



namespace std {
  	template<typename I, typename V>
  	struct tuple_size<stx::enumerate_pair<I, V>>
		: std::integral_constant<std::size_t, 2> {};

	template<typename I, typename V>
	struct tuple_element<0, stx::enumerate_pair<I, V>> {
		using type = I;
	};

	template<typename I, typename V>
	struct tuple_element<1, stx::enumerate_pair<I, V>> {
		using type = V*;
	};
}


namespace stx {
	template<typename Container>
	using iterator_of = decltype(std::begin(std::declval<Container&>()));
	
	template<typename Container>
	using const_iterator_of = decltype(std::cbegin(std::declval<const Container&>()));
	
	template<typename Index, typename Iterator>
	class enumerate_iterator {
	public:
		using iterator_category = std::input_iterator_tag;
		using difference_type = std::ptrdiff_t;
		// using value_type = typename Iterator::value_type;
		// using pointer = value_type*;
		// using reference = value_type&;


		constexpr enumerate_iterator(Iterator iter, Index index) 
		: iter{iter}, index{index} {}



		constexpr auto operator*() const {
			return enumerate_pair{this->index, &*this->iter};
		}

		constexpr auto operator*() {
			return enumerate_pair{this->index, &*this->iter};
		}



		constexpr enumerate_iterator operator++() {
			this->index++;
			this->iter++;
			return *this;
		}

		constexpr enumerate_iterator operator++(int) {
			auto temp = *this;
			this->index++;
			this->iter++;
			return temp;
		}



		constexpr friend bool operator==(const enumerate_iterator & l, const enumerate_iterator & r) {
			return l.iter == r.iter;
		}

		constexpr friend bool operator!=(const enumerate_iterator & l, const enumerate_iterator & r) {
			return l.iter != r.iter;
		}



		Iterator iter;
		Index index;
	};



	template<std::integral Index, typename Container> 
	class enumerate_range {
	public:

		using iterator = enumerate_iterator<Index, iterator_of<Container>>;
		using const_iterator = enumerate_iterator<Index, const_iterator_of<Container>>;


		enumerate_range(Container & container) : container{container} {}



		constexpr auto begin() {
			return iterator{std::begin(container), 0};
		}

		constexpr auto end() {
			return iterator{std::end(container), static_cast<Index>(std::size(container))};
		}

		
		
		constexpr auto begin() const {
			return const_iterator{std::begin(container), 0};
		}

		constexpr auto end() const {
			return const_iterator{std::end(container), static_cast<Index>(std::size(container))};
		}



		constexpr auto cbegin() const {
			return const_iterator{std::cbegin(container), 0};
		}

		constexpr auto cend() const {
			return const_iterator{std::cend(container), static_cast<Index>(std::size(container))};
		}

	private:
		Container & container;
	};



	template<std::integral Index, typename Container> 
	class const_enumerate_range {
	public:

		using const_iterator = enumerate_iterator<Index, const_iterator_of<Container>>;


		const_enumerate_range(const Container & container) : container{container} {}


		
		constexpr auto begin() const {
			return const_iterator{std::begin(container), 0};
		}

		constexpr auto end() const {
			return const_iterator{std::end(container), static_cast<Index>(std::size(container))};
		}



		constexpr auto cbegin() const {
			return const_iterator{std::cbegin(container), 0};
		}

		constexpr auto cend() const {
			return const_iterator{std::cend(container), static_cast<Index>(std::size(container))};
		}

	private:
		const Container & container;
	};



	template<std::integral Index = std::size_t, typename Container> 
	auto enumerate(Container & container) {
		return enumerate_range<Index, Container>{container};
	}



	template<std::integral Index = std::size_t, typename Container> 
	auto enumerate(const Container & container) {
		return const_enumerate_range<Index, Container>{container};
	}
}