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



	CPHINX_TEST(wrapped_just_5) {
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
}
