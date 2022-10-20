#pragma once
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

	private:
		Index i;
		Value * v;
	};



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



	template<typename Index, typename Iterator>
	class const_enumerate_iterator {
	public:
		using iterator_category = std::input_iterator_tag;
		using difference_type = std::ptrdiff_t;
		// using value_type = const typename Iterator::value_type;
		// using pointer = value_type*;
		// using reference = value_type&;

		// using pair = enumerate_pair<Index, value_type>;



		constexpr const_enumerate_iterator(Iterator iter, Index index) 
		: iter{iter}, index{index} {}



		constexpr auto operator*() const {
			return enumerate_pair{this->index, &*this->iter};
		}

		constexpr auto operator*() {
			return enumerate_pair{this->index, &*this->iter};
		}



		constexpr const_enumerate_iterator operator++() {
			this->index++;
			this->iter++;
			return *this;
		}

		constexpr const_enumerate_iterator operator++(int) {
			auto temp = *this;
			this->index++;
			this->iter++;
			return temp;
		}



		constexpr friend bool operator==(const const_enumerate_iterator & l, const const_enumerate_iterator & r) {
			return l.iter == r.iter;
		}

		constexpr friend bool operator!=(const const_enumerate_iterator & l, const const_enumerate_iterator & r) {
			return l.iter != r.iter;
		}



		Iterator iter;
		Index index;
	};



	template<std::integral Index, typename Container> 
	class enumerate_range {
	public:

		using iterator = enumerate_iterator<Index, typename Container::iterator>;
		using const_iterator = const_enumerate_iterator<Index, typename Container::const_iterator>;


		enumerate_range(Container & container) : container{container} {}



		constexpr auto begin() {
			return iterator{container.begin(), 0};
		}

		constexpr auto end() {
			return iterator{container.end(), static_cast<Index>(container.size())};
		}

		
		
		constexpr auto begin() const {
			return const_iterator{container.begin(), 0};
		}

		constexpr auto end() const {
			return const_iterator{container.end(), static_cast<Index>(container.size())};
		}



		constexpr auto cbegin() const {
			return const_iterator{container.cbegin(), 0};
		}

		constexpr auto cend() const {
			return const_iterator{container.cend(), static_cast<Index>(container.size())};
		}

	private:
		Container & container;
	};



	template<std::integral Index, typename Container> 
	class const_enumerate_range {
	public:

		using const_iterator = const_enumerate_iterator<Index, typename Container::const_iterator>;


		const_enumerate_range(const Container & container) : container{container} {}


		
		constexpr auto begin() const {
			return const_iterator{container.begin(), 0};
		}

		constexpr auto end() const {
			return const_iterator{container.end(), static_cast<Index>(container.size())};
		}



		constexpr auto cbegin() const {
			return const_iterator{container.cbegin(), 0};
		}

		constexpr auto cend() const {
			return const_iterator{container.cend(), static_cast<Index>(container.size())};
		}

	private:
		const Container & container;
	};



	template<std::integral Index, typename Container> 
	auto enumerate(Container & container) {
		return enumerate_range<Index, Container>{container};
	}



	template<std::integral Index, typename Container> 
	auto enumerate(const Container & container) {
		return const_enumerate_range<Index, Container>{container};
	}
}