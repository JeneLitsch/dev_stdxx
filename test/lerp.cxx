#include "stdxx/math.hxx"
#include "cphinx/cphinx.hxx"


CPHINX_TEST(lerp_numeric_at_0) {
    cphinx.assert_equal(stx::lerp<int>(0, 20, 0.f), 0);
    cphinx.assert_equal(stx::lerp<float>(0.f, 20.f, 0.f), 0.f);
}



CPHINX_TEST(lerp_numeric_at_1) {
    cphinx.assert_equal(stx::lerp<int>(0, 20, 1.f), 20);
    cphinx.assert_equal(stx::lerp<float>(0.f, 20.f, 1.f), 20.f);
}



CPHINX_TEST(lerp_numeric_ascn) {
    cphinx.assert_equal(stx::lerp<int>(0, 20, 0.5), 10);
    cphinx.assert_equal(stx::lerp<int>(-20, 20, 0.5), 0);
    cphinx.assert_equal(stx::lerp<float>(0.f, 20.f, 0.5), 10.f);
    cphinx.assert_equal(stx::lerp<float>(-20.f, 20.f, 0.5), 0.f);
}



CPHINX_TEST(lerp_numeric_desc) {
    cphinx.assert_equal(stx::lerp<int>(20, 0, 0.5), 10);
    cphinx.assert_equal(stx::lerp<int>(20, -20, 0.5), 0);
    cphinx.assert_equal(stx::lerp<unsigned>(20, 0, 0.5), 10);
    cphinx.assert_equal(stx::lerp<float>(20.f, 0.f, 0.5), 10.f);
    cphinx.assert_equal(stx::lerp<float>(20.f, -20.f, 0.5), 0.f);
}



CPHINX_TEST(lerp_vector2_at_0) {
    cphinx.assert_equal(stx::lerp<stx::vector2i>({0,0}, {10,10}, 0.f), stx::vector2i{0, 0});
    cphinx.assert_equal(stx::lerp<stx::vector2u>({0,0}, {10,10}, 0.f), stx::vector2u{0, 0});
    cphinx.assert_equal(stx::lerp<stx::vector2f>({0,0}, {10,10}, 0.f), stx::vector2f{0, 0});
}



CPHINX_TEST(lerp_vector2_at_1) {
    cphinx.assert_equal(stx::lerp<stx::vector2i>({0,0}, {10,10}, 1.f), stx::vector2i{10, 10});
    cphinx.assert_equal(stx::lerp<stx::vector2u>({0,0}, {10,10}, 1.f), stx::vector2u{10, 10});
    cphinx.assert_equal(stx::lerp<stx::vector2f>({0,0}, {10,10}, 1.f), stx::vector2f{10, 10});
}



CPHINX_TEST(lerp_vector2_ascn) {
    cphinx.assert_equal(stx::lerp<stx::vector2i>({0,0}, {10,10}, 0.5f), stx::vector2i{5, 5});
    cphinx.assert_equal(stx::lerp<stx::vector2u>({0,0}, {10,10}, 0.5f), stx::vector2u{5, 5});
    cphinx.assert_equal(stx::lerp<stx::vector2f>({0,0}, {10,10}, 0.5f), stx::vector2f{5, 5});
}



CPHINX_TEST(lerp_vector2_desc) {
    cphinx.assert_equal(stx::lerp<stx::vector2i>({10,10}, {0,0}, 0.5f), stx::vector2i{5, 5});
    cphinx.assert_equal(stx::lerp<stx::vector2u>({10,10}, {0,0}, 0.5f), stx::vector2u{5, 5});
    cphinx.assert_equal(stx::lerp<stx::vector2f>({10,10}, {0,0}, 0.5f), stx::vector2f{5, 5});
}



CPHINX_TEST(lerp_vector3_at_0) {
    cphinx.assert_equal(stx::lerp<stx::vector3i>({0,0,0}, {10,10,10}, 0.f), stx::vector3i{0,0,0});
    cphinx.assert_equal(stx::lerp<stx::vector3u>({0,0,0}, {10,10,10}, 0.f), stx::vector3u{0,0,0});
    cphinx.assert_equal(stx::lerp<stx::vector3f>({0,0,0}, {10,10,10}, 0.f), stx::vector3f{0,0,0});
}



CPHINX_TEST(lerp_vector3_at_1) {
    cphinx.assert_equal(stx::lerp<stx::vector3i>({0,0,0}, {10,10,10}, 1.f), stx::vector3i{10,10,10});
    cphinx.assert_equal(stx::lerp<stx::vector3u>({0,0,0}, {10,10,10}, 1.f), stx::vector3u{10,10,10});
    cphinx.assert_equal(stx::lerp<stx::vector3f>({0,0,0}, {10,10,10}, 1.f), stx::vector3f{10,10,10});
}



CPHINX_TEST(lerp_vector3_ascn) {
    cphinx.assert_equal(stx::lerp<stx::vector3i>({0,0,0}, {10,10,10}, 0.5f), stx::vector3i{5,5,5});
    cphinx.assert_equal(stx::lerp<stx::vector3u>({0,0,0}, {10,10,10}, 0.5f), stx::vector3u{5,5,5});
    cphinx.assert_equal(stx::lerp<stx::vector3f>({0,0,0}, {10,10,10}, 0.5f), stx::vector3f{5,5,5});
}



CPHINX_TEST(lerp_vector3_desc) {
    cphinx.assert_equal(stx::lerp<stx::vector3i>({10,10,10}, {0,0,0}, 0.5f), stx::vector3i{5,5,5});
    cphinx.assert_equal(stx::lerp<stx::vector3u>({10,10,10}, {0,0,0}, 0.5f), stx::vector3u{5,5,5});
    cphinx.assert_equal(stx::lerp<stx::vector3f>({10,10,10}, {0,0,0}, 0.5f), stx::vector3f{5,5,5});
}