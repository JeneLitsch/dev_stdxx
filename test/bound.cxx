#include "cphinx/cphinx.hxx"
#include "proto/bound.hxx"

CPHINX_TEST(bound_min) {
	stx::bound<int, 10, 10> a{0};
	cphinx.assert_equal(a.min(), 10, "a.min() is not 10");
	
	stx::bound<int, -20, -10> b{0};
	cphinx.assert_equal(b.min(), -20, "b.min() is not -20");
}



CPHINX_TEST(bound_max) {
	stx::bound<int, -20, 10> a{0};
	cphinx.assert_equal(a.max(), 10, "a.max() is not 10");
	
	stx::bound<int, -20, -10> b{0};
	cphinx.assert_equal(b.max(), -10, "b.max() is not -10");
}



CPHINX_TEST(bound_clamp) {
	stx::bound<int, 0, 10> a {-10};
	stx::bound<int, 0, 10> b { 20};

	cphinx.assert_equal(*a, 0, "Must be clamped to 0");
	cphinx.assert_equal(*b, 10, "Must be clamped to 10");
}



CPHINX_TEST(bound_add) {
	stx::bound<int, 0, 20> a {15};
	stx::bound<int, -10, 10> b {-5};

	auto r1 = a + b;
	auto r2 = b + a;

	cphinx.assert_equal(*r1,       10, "Result must be 10");
	cphinx.assert_equal(r1.min(), -10, "Result max be -10");
	cphinx.assert_equal(r1.max(),  30, "Result max be 20");

	cphinx.assert_equal(*r2,       10, "Result must be 10");
	cphinx.assert_equal(r2.min(), -10, "Result max be -10");
	cphinx.assert_equal(r2.max(),  30, "Result max be 20");
}



CPHINX_TEST(bound_sub) {
	stx::bound<int, 0, 20> a {0};
	stx::bound<int, 30, 40> b {35};

	auto r1 = a - b;
	auto r2 = b - a;

	cphinx.assert_equal(*r1,       -35);
	cphinx.assert_equal(r1.min(),  -40);
	cphinx.assert_equal(r1.max(),  -10);

	cphinx.assert_equal(*r2,       35);
	cphinx.assert_equal(r2.min(),  10);
	cphinx.assert_equal(r2.max(),  40);
}



CPHINX_TEST(bound_mlt) {
	stx::bound<int, -30, 20>  a {15};
	stx::bound<int, -20, 10> b {-5};

	auto r1 = a * b;
	auto r2 = b * a;

	cphinx.assert_equal(*r1,       -75);
	cphinx.assert_equal(r1.min(), -400);
	cphinx.assert_equal(r1.max(),  600);

	cphinx.assert_equal(*r2,       -75);
	cphinx.assert_equal(r2.min(), -400);
	cphinx.assert_equal(r2.max(),  600);
}



CPHINX_TEST(bound_div) {
	stx::bound<int, -30, 20>  a {15};
	stx::bound<int, -20, 10>  b {-5};

	auto r1 = a / b;
	auto r2 = b / a;

	cphinx.assert_equal(*r1,      -3);
	cphinx.assert_equal(r1.min(), -3);
	cphinx.assert_equal(r1.max(), 2);

	cphinx.assert_equal(*r2,      0);
	cphinx.assert_equal(r2.min(), -1);
	cphinx.assert_equal(r2.max(), 0);
}



// CPHINX_TEST(bound_mod) {
// 	stx::bound<int, -30, 20>  a {15};
// 	stx::bound<int, -20, 10>  b {4};

// 	auto r1 = a % b;
// 	auto r2 = b % a;

// 	cphinx.assert_equal(*r1,      1);
// 	cphinx.assert_equal(r1.min(), -3);
// 	cphinx.assert_equal(r1.max(), 2);

// 	cphinx.assert_equal(*r2,      4);
// 	cphinx.assert_equal(r2.min(), -1);
// 	cphinx.assert_equal(r2.max(), 0);
// }