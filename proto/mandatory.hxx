#pragma once

namespace stx {
	template<typename T>
	class mandatory {
	public:
		template<typename T2>
		mandatory(const T2 & t) {
			this->t = t;
		}



		template<typename T2>
		mandatory(T2 && t) {
			this->t = std::move(t);
		}


		
		mandatory(const mandatory & other) {
			this->t = other.t;
		}

		mandatory & operator=(const mandatory & other) {
			this->t = other.t;
			return *this;
		}

		mandatory(mandatory && other) {
			this->t = std::move(other.t);
		}

		mandatory & operator=(mandatory && other) {
			this->t = std::move(other.t);
			return *this;
		}

		~mandatory() = default;

		operator T & () {
			return this->t;
		} 

		operator const T & () const {
			return this->t;
		} 
		
	private:
		T t;
	};
}