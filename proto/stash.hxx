#pragma once

namespace stx {
	template<typename ...Args>
	class keys {};

	template<typename ...Args>
	class values {};

	template<typename ...Args>
	class basic_stash;


	template<typename ... Keys, typename ... Values>
	class basic_stash<keys<Keys...>, values<Values...>> {
	private:
		struct KeyBase {

		};

		template<typename T>
		struct KeyImpl : KeyBase {
			T t;
		};

		struct ValBase {

		};

		template<typename T>
		struct ValImpl : ValBase {
			T t;
		};

		struct Map {
			
		};

	public:


	private:

	};
}