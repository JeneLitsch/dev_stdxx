#include "stdxx/math.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(remap_indentity) {
    cphinx.assert_equal(stx::remap<unsigned, unsigned>(0, 10, 0, 10, 5), 5);
    cphinx.assert_equal(stx::remap<int, int>(0, 10, 0, 10, 5), 5);
    cphinx.assert_equal(stx::remap<float, float>(0, 10, 0, 10, 5), 5);
    cphinx.assert_equal(stx::remap<double, double>(0, 10, 0, 10, 5), 5);
}



CPHINX_TEST(remap_clamp) {
    cphinx.assert_equal(stx::remap<unsigned, unsigned>(0, 10, 0, 10, 20), 10);
    cphinx.assert_equal(stx::remap<int, int>(0, 10, 0, 10, 20), 10);
    cphinx.assert_equal(stx::remap<float, float>(0, 10, 0, 10, 20), 10);
    cphinx.assert_equal(stx::remap<double, double>(0, 10, 0, 10, 20), 10);
}