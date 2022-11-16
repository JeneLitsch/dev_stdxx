#include "cphinx/cphinx.hxx"
#include "stdxx/vector.hxx"

bool is_successful(auto fx) {
	try{
		fx();
		return true;
	}
	catch(...) {
		return false;
	}
}


CPHINX_TEST(vector3_ctor_float) {
	constexpr static stx::vector3f vec {-1,2,-3};
	cphinx.assert_equal(vec.x, -1, "Invalid x");
	cphinx.assert_equal(vec.y,  2, "Invalid y");
	cphinx.assert_equal(vec.z,  -3, "Invalid z");
}



CPHINX_TEST(vector3_index) {
	constexpr static stx::vector3f v1 {-1,2,-3};
	cphinx.assert_equal(v1[0], -1, "Invalid x");
	cphinx.assert_equal(v1[1],  2, "Invalid y");
	cphinx.assert_equal(v1[2], -3, "Invalid z");
	cphinx.assert_true(is_successful([&] { v1[0]; }));
	cphinx.assert_true(is_successful([&] { v1[1]; }));
	cphinx.assert_true(is_successful([&] { v1[2]; }));
	cphinx.assert_false(is_successful([&] { v1[3]; }));

	constexpr static stx::vector3f v2 {-1,2,-3};
	cphinx.assert_equal(v2[0], -1, "Invalid x");
	cphinx.assert_equal(v2[1],  2, "Invalid y");
	cphinx.assert_equal(v2[2], -3, "Invalid z");
	cphinx.assert_true(is_successful([&] { v2[0]; }));
	cphinx.assert_true(is_successful([&] { v2[1]; }));
	cphinx.assert_true(is_successful([&] { v2[2]; }));
	cphinx.assert_false(is_successful([&] { v2[3]; }));
}