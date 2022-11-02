#include "stdxx/math.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(remap_indentity) {
    cphinx.assert_equal(stx::remap<unsigned, unsigned>(0, 10, 0, 10, 5), 5u);
    cphinx.assert_equal(stx::remap<int, int>(0, 10, 0, 10, 5), 5);
    cphinx.assert_equal(stx::remap<float, float>(0, 10, 0, 10, 5), 5.f);
    cphinx.assert_equal(stx::remap<double, double>(0, 10, 0, 10, 5), 5.f);
}



CPHINX_TEST(remap_clamp_high) {
    cphinx.assert_equal(stx::remap<unsigned, unsigned>(0, 10, 0, 10, 20), 10u);
    cphinx.assert_equal(stx::remap<int, int>(0, 10, 0, 10, 20), 10);
    cphinx.assert_equal(stx::remap<float, float>(0, 10, 0, 10, 20), 10.f);
    cphinx.assert_equal(stx::remap<double, double>(0, 10, 0, 10, 20), 10.f);
}



CPHINX_TEST(remap_clamp_low) {
    cphinx.assert_equal(stx::remap<unsigned, unsigned>(10, 20, 10, 20, 5), 10u);
    cphinx.assert_equal(stx::remap<int, int>(0, 10, 0, 10, -10), 0);
    cphinx.assert_equal(stx::remap<float, float>(0, 10, 0, 10, -10), 0.f);
    cphinx.assert_equal(stx::remap<double, double>(0, 10, 0, 10, -10), 0.f);
}



CPHINX_TEST(remap_transform_ascn_to_ascn) {
    cphinx.assert_equal(stx::remap<float, int>(0.f, 3.f, 0, 10, 1.5), 5);
    cphinx.assert_equal(stx::remap<float, float>(0.f, 1.f, -1.f, 1.f, 0.5), 0.f);
    cphinx.assert_equal(stx::remap<int, int>(-100, 0, 0, 100, -50), 50);
}



CPHINX_TEST(remap_transform_ascn_to_desc) {
    cphinx.assert_equal(stx::remap<float, float>(0.f, 3.f, 9, 0, 1.f), 6);
    cphinx.assert_equal(stx::remap<float, float>(0.f, 1.f, 1.f, -1.f, 0.5), 0.f);
}



CPHINX_TEST(remap_transform_desc_to_ascn) {
    cphinx.assert_equal(stx::remap<int, int>(10, 0, 0, 100, 6), 40);
}



CPHINX_TEST(remap_transform_desc_to_desc) {
    cphinx.assert_equal(stx::remap<int, int>(10, 0, 100, 0, 6), 60);
}