#include "cphinx/cphinx.hxx"
#include "stdxx/math.hxx"

namespace test {
	CPHINX_TEST(wrapped_just_0) {
		auto a = stx::wrapped_i{0,0,0};
		validator.assert_equal(*a, 0);
		--a;
		validator.assert_equal(*a, 0);
		++a;
		validator.assert_equal(*a, 0);
		a--;
		validator.assert_equal(*a, 0);
		a++;
	}



	CPHINX_TEST(wrapped_just_5) {
		auto a = stx::wrapped_i{5,5,5};
		validator.assert_equal(*a, 5);
		--a;
		validator.assert_equal(*a, 5);
		++a;
		validator.assert_equal(*a, 5);
		a--;
		validator.assert_equal(*a, 5);
		a++;
	}



	CPHINX_TEST(wrapped_just_m5) {
		auto a = stx::wrapped_i{-5,-5,-5};
		validator.assert_equal(*a, -5);
		--a;
		validator.assert_equal(*a, -5);
		++a;
		validator.assert_equal(*a, -5);
		a--;
		validator.assert_equal(*a, -5);
		a++;
	}



	CPHINX_TEST(wrapped_predec) {
		auto a = stx::wrapped_i{-10, -10, 10};
		auto b = --a;
		validator.assert_equal(*a, 10);
		validator.assert_equal(*b, 10);
	}


	
	CPHINX_TEST(wrapped_postdec) {
		auto a = stx::wrapped_i{-10, -10, 10};
		auto b = a--;
		validator.assert_equal(*a, 10);
		validator.assert_equal(*b, -10);
	}



	CPHINX_TEST(wrapped_preinc) {
		auto a = stx::wrapped_i{10, -10, 10};
		auto b = ++a;
		validator.assert_equal(*a, -10);
		validator.assert_equal(*b, -10);
	}


	
	CPHINX_TEST(wrapped_postinc) {
		auto a = stx::wrapped_i{10, -10, 10};
		auto b = a++;
		validator.assert_equal(*a, -10);
		validator.assert_equal(*b, 10);
	}



	CPHINX_TEST(wrapped_min) {
		auto a = stx::wrapped_i{0, -10, 10};
		auto b = stx::wrapped_i{10, 10, 20};
		validator.assert_equal(a.min(), -10);
		validator.assert_equal(b.min(), 10);
	}



	CPHINX_TEST(wrapped_max) {
		auto a = stx::wrapped_i{0, -10, 10};
		auto b = stx::wrapped_i{10, 10, 20};
		validator.assert_equal(a.max(), 10);
		validator.assert_equal(b.max(), 20);
	}



	CPHINX_TEST(wrapped_ctor_wrap) {
		auto a = stx::wrapped_i{9, 10, 20};
		auto b = stx::wrapped_i{21, 10, 20};
		validator.assert_equal(*a, 20);
		validator.assert_equal(*b, 10);

		auto c = stx::wrapped_i{8, 10, 20};
		auto d = stx::wrapped_i{22, 10, 20};
		validator.assert_equal(*c, 19);
		validator.assert_equal(*d, 11);

		auto e = stx::wrapped_i{5, 10, 20};
		auto f = stx::wrapped_i{25, 10, 20};
		validator.assert_equal(*e, 16);
		validator.assert_equal(*f, 14);

		auto g = stx::wrapped_i{0, 10, 20};
		auto h = stx::wrapped_i{30, 10, 20};
		validator.assert_equal(*g, 11);
		validator.assert_equal(*h, 19);
	}
}
