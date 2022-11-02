#include "cphinx/cphinx.hxx"
#include "stdxx/math.hxx"

CPHINX_TEST(wrapped_just_0) {
	auto a = stx::wrapped_i{0,0,0};
	cphinx.assert_equal(*a, 0);
	--a;
	cphinx.assert_equal(*a, 0);
	++a;
	cphinx.assert_equal(*a, 0);
	a--;
	cphinx.assert_equal(*a, 0);
	a++;
}



CPHINX_TEST(wrapped_just_5) {
	auto a = stx::wrapped_i{5,5,5};
	cphinx.assert_equal(*a, 5);
	--a;
	cphinx.assert_equal(*a, 5);
	++a;
	cphinx.assert_equal(*a, 5);
	a--;
	cphinx.assert_equal(*a, 5);
	a++;
}



CPHINX_TEST(wrapped_just_m5) {
	auto a = stx::wrapped_i{-5,-5,-5};
	cphinx.assert_equal(*a, -5);
	--a;
	cphinx.assert_equal(*a, -5);
	++a;
	cphinx.assert_equal(*a, -5);
	a--;
	cphinx.assert_equal(*a, -5);
	a++;
}



CPHINX_TEST(wrapped_predec) {
	auto a = stx::wrapped_i{-10, -10, 10};
	auto b = --a;
	cphinx.assert_equal(*a, 10);
	cphinx.assert_equal(*b, 10);
}



CPHINX_TEST(wrapped_postdec) {
	auto a = stx::wrapped_i{-10, -10, 10};
	auto b = a--;
	cphinx.assert_equal(*a, 10);
	cphinx.assert_equal(*b, -10);
}



CPHINX_TEST(wrapped_preinc) {
	auto a = stx::wrapped_i{10, -10, 10};
	auto b = ++a;
	cphinx.assert_equal(*a, -10);
	cphinx.assert_equal(*b, -10);
}



CPHINX_TEST(wrapped_postinc) {
	auto a = stx::wrapped_i{10, -10, 10};
	auto b = a++;
	cphinx.assert_equal(*a, -10);
	cphinx.assert_equal(*b, 10);
}



CPHINX_TEST(wrapped_min) {
	auto a = stx::wrapped_i{0, -10, 10};
	auto b = stx::wrapped_i{10, 10, 20};
	cphinx.assert_equal(a.min(), -10);
	cphinx.assert_equal(b.min(), 10);
}



CPHINX_TEST(wrapped_max) {
	auto a = stx::wrapped_i{0, -10, 10};
	auto b = stx::wrapped_i{10, 10, 20};
	cphinx.assert_equal(a.max(), 10);
	cphinx.assert_equal(b.max(), 20);
}



CPHINX_TEST(wrapped_ctor_wrap) {
	auto a = stx::wrapped_i{9, 10, 20};
	auto b = stx::wrapped_i{21, 10, 20};
	cphinx.assert_equal(*a, 20);
	cphinx.assert_equal(*b, 10);

	auto c = stx::wrapped_i{8, 10, 20};
	auto d = stx::wrapped_i{22, 10, 20};
	cphinx.assert_equal(*c, 19);
	cphinx.assert_equal(*d, 11);

	auto e = stx::wrapped_i{5, 10, 20};
	auto f = stx::wrapped_i{25, 10, 20};
	cphinx.assert_equal(*e, 16);
	cphinx.assert_equal(*f, 14);

	auto g = stx::wrapped_i{0, 10, 20};
	auto h = stx::wrapped_i{30, 10, 20};
	cphinx.assert_equal(*g, 11);
	cphinx.assert_equal(*h, 19);
}