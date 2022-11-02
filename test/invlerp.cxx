#include "stdxx/math.hxx"
#include "cphinx/cphinx.hxx"


CPHINX_TEST(invlerp_ascn) {
    cphinx.assert_equal(stx::invlerp<unsigned>(0, 10, 0), 0.0);
    cphinx.assert_equal(stx::invlerp<int>(0, 10, 0), 0.0);
    cphinx.assert_equal(stx::invlerp<float>(0, 10, 0), 0.0);
    cphinx.assert_equal(stx::invlerp<double>(0, 10, 0), 0.0);

    cphinx.assert_equal(stx::invlerp<unsigned>(0, 10, 10), 1.0);
    cphinx.assert_equal(stx::invlerp<int>(0, 10, 10), 1.0);
    cphinx.assert_equal(stx::invlerp<float>(0, 10, 10), 1.0);
    cphinx.assert_equal(stx::invlerp<double>(0, 10, 10), 1.0);

    cphinx.assert_equal(stx::invlerp<unsigned>(0, 10, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<int>(0, 10, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<float>(0, 10, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<double>(0, 10, 5), 0.5);
}



CPHINX_TEST(invlerp_desc) {
    cphinx.assert_equal(stx::invlerp<unsigned>(10, 0, 10), 0.0);
    cphinx.assert_equal(stx::invlerp<int>(10, 0, 10), 0.0);
    cphinx.assert_equal(stx::invlerp<float>(10, 0, 10), 0.0);
    cphinx.assert_equal(stx::invlerp<double>(10, 0, 10), 0.0);

    cphinx.assert_equal(stx::invlerp<unsigned>(10, 0, 0), 1.0);
    cphinx.assert_equal(stx::invlerp<int>(10, 0, 0), 1.0);
    cphinx.assert_equal(stx::invlerp<float>(10, 0, 0), 1.0);
    cphinx.assert_equal(stx::invlerp<double>(10, 0, 0), 1.0);

    cphinx.assert_equal(stx::invlerp<unsigned>(10, 0, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<int>(10, 0, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<float>(10, 0, 5), 0.5);
    cphinx.assert_equal(stx::invlerp<double>(10, 0, 5), 0.5);
}