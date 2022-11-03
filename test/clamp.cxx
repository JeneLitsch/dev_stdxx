#include "stdxx/math.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(clamp_in_range) {
	cphinx.assert_equal(stx::clamp<unsigned>(5, 0, 10), 5);
	cphinx.assert_equal(stx::clamp<int>(5, 0, 10), 5);
	cphinx.assert_equal(stx::clamp<float>(1.5f, 0.f, 3.f), 1.5f);
	cphinx.assert_equal(stx::clamp<double>(1.5, 0.0, 3.0), 1.5);
}



CPHINX_TEST(clamp_low) {
	cphinx.assert_equal(stx::clamp<unsigned>(0, 5, 10), 5);
	cphinx.assert_equal(stx::clamp<int>(-10, 0, 10), 0);
	cphinx.assert_equal(stx::clamp<float>(-5.f, 0.f, 3.f), 0.f);
	cphinx.assert_equal(stx::clamp<double>(-5.0, 0.0, 3.0), 0.0);
}



CPHINX_TEST(clamp_high) {
	cphinx.assert_equal(stx::clamp<unsigned>(12, 0, 10), 10);
	cphinx.assert_equal(stx::clamp<int>(12, 0, 10), 10);
	cphinx.assert_equal(stx::clamp<float>(5.f, 0.f, 3.f), 3.f);
	cphinx.assert_equal(stx::clamp<double>(5.0, 0.0, 3.0), 3.0);
}



CPHINX_TEST(clamp_vector2_in_range) {
	cphinx.assert_equal(stx::clamp<stx::vector2u>({5,5}, {0,0}, {10,10}), stx::vector2u{5,5});
	cphinx.assert_equal(stx::clamp<stx::vector2i>({5,5}, {0,0}, {10,10}), stx::vector2i{5,5});
	cphinx.assert_equal(stx::clamp<stx::vector2f>({5,5}, {0,0}, {10,10}), stx::vector2f{5,5});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({5,5}, {0,0}, {10,10}), stx::vector2d{5,5});
}



CPHINX_TEST(clamp_vector2_low) {
	cphinx.assert_equal(stx::clamp<stx::vector2u>({0,  0}, {5,5}, {10,10}), stx::vector2u{5,5});
	cphinx.assert_equal(stx::clamp<stx::vector2i>({-5,-5}, {0,0}, {10,10}), stx::vector2i{0,0});
	cphinx.assert_equal(stx::clamp<stx::vector2f>({-5,-5}, {0,0}, {10,10}), stx::vector2f{0,0});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({-5,-5}, {0,0}, {10,10}), stx::vector2d{0,0});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({5,-5}, {0,0}, {10,10}), stx::vector2d{5,0});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({-5,5}, {0,0}, {10,10}), stx::vector2d{0,5});
}



CPHINX_TEST(clamp_vector2_high) {
	cphinx.assert_equal(stx::clamp<stx::vector2u>({20,20}, {0,0}, {10,10}), stx::vector2u{10,10});
	cphinx.assert_equal(stx::clamp<stx::vector2i>({20,20}, {0,0}, {10,10}), stx::vector2i{10,10});
	cphinx.assert_equal(stx::clamp<stx::vector2f>({20,20}, {0,0}, {10,10}), stx::vector2f{10,10});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({20,20}, {0,0}, {10,10}), stx::vector2d{10,10});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({5,20}, {0,0}, {10,10}), stx::vector2d{5,10});
	cphinx.assert_equal(stx::clamp<stx::vector2d>({20,5}, {0,0}, {10,10}), stx::vector2d{10,5});
}



CPHINX_TEST(clamp_vector3_in_range) {
	cphinx.assert_equal(stx::clamp<stx::vector3u>({5,5,5}, {0,0,0}, {10,10,10}), stx::vector3u{5,5,5});
	cphinx.assert_equal(stx::clamp<stx::vector3i>({5,5,5}, {0,0,0}, {10,10,10}), stx::vector3i{5,5,5});
	cphinx.assert_equal(stx::clamp<stx::vector3f>({5,5,5}, {0,0,0}, {10,10,10}), stx::vector3f{5,5,5});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({5,5,5}, {0,0,0}, {10,10,10}), stx::vector3d{5,5,5});
}



CPHINX_TEST(clamp_vector3_low) {
	cphinx.assert_equal(stx::clamp<stx::vector3u>({0, 0, 0}, {5,5,5}, {10,10,10}), stx::vector3u{5,5,5});
	cphinx.assert_equal(stx::clamp<stx::vector3i>({-5,-5,-5}, {0,0,0}, {10,10,10}), stx::vector3i{0,0,0});
	cphinx.assert_equal(stx::clamp<stx::vector3f>({-5,-5,-5}, {0,0,0}, {10,10,10}), stx::vector3f{0,0,0});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({-5,-5,-5}, {0,0,0}, {10,10,10}), stx::vector3d{0,0,0});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({5,-5,-5}, {0,0,0}, {10,10,10}),  stx::vector3d{5,0,0});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({-5,5,-5}, {0,0,0}, {10,10,10}),  stx::vector3d{0,5,0});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({-5,-5,5}, {0,0,0}, {10,10,10}),  stx::vector3d{0,0,5});
}



CPHINX_TEST(clamp_vector3_high) {
	cphinx.assert_equal(stx::clamp<stx::vector3u>({20,20,20}, {0,0,0}, {10,10,10}), stx::vector3u{10,10,10});
	cphinx.assert_equal(stx::clamp<stx::vector3i>({20,20,20}, {0,0,0}, {10,10,10}), stx::vector3i{10,10,10});
	cphinx.assert_equal(stx::clamp<stx::vector3f>({20,20,20}, {0,0,0}, {10,10,10}), stx::vector3f{10,10,10});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({20,20,20}, {0,0,0}, {10,10,10}), stx::vector3d{10,10,10});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({5,20,20}, {0,0,0}, {10,10,10}),  stx::vector3d{5,10,10});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({20,5,20}, {0,0,0}, {10,10,10}),  stx::vector3d{10,5,10});
	cphinx.assert_equal(stx::clamp<stx::vector3d>({20,20,5}, {0,0,0}, {10,10,10}),  stx::vector3d{10,10,5});
}