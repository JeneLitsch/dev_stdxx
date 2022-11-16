#include "cphinx/cphinx.hxx"
#include "proto/vectorN.hxx"

CPHINX_TEST(vectorN_ctor_default) {
	stx::vectorN<float, 4> vec4f;
	cphinx.assert_equal(vec4f[0], 0.f);
	cphinx.assert_equal(vec4f[1], 0.f);
	cphinx.assert_equal(vec4f[2], 0.f);
	cphinx.assert_equal(vec4f[3], 0.f);

	stx::vectorN<int, 4> vec4i;
	cphinx.assert_equal(vec4i[0], 0);
	cphinx.assert_equal(vec4i[1], 0);
	cphinx.assert_equal(vec4i[2], 0);
	cphinx.assert_equal(vec4i[3], 0);
}



CPHINX_TEST(vectorN_ctor_elements) {
	stx::vectorN<float, 4> vec4f = {1,2,3,4};
	cphinx.assert_equal(vec4f[0], 1.f);
	cphinx.assert_equal(vec4f[1], 2.f);
	cphinx.assert_equal(vec4f[2], 3.f);
	cphinx.assert_equal(vec4f[3], 4.f);

	stx::vectorN<int, 4> vec4i {1,2,3,4};
	cphinx.assert_equal(vec4i[0], 1);
	cphinx.assert_equal(vec4i[1], 2);
	cphinx.assert_equal(vec4i[2], 3);
	cphinx.assert_equal(vec4i[3], 4);
}



CPHINX_TEST(vectorN_ctor_single) {
	stx::vectorN<float, 4> vec4f{2};
	cphinx.assert_equal(vec4f[0], 2.f);
	cphinx.assert_equal(vec4f[1], 2.f);
	cphinx.assert_equal(vec4f[2], 2.f);
	cphinx.assert_equal(vec4f[3], 2.f);

	stx::vectorN<int, 4> vec4i {1,2,3,4};
	cphinx.assert_equal(vec4i[0], 1);
	cphinx.assert_equal(vec4i[1], 2);
	cphinx.assert_equal(vec4i[2], 3);
	cphinx.assert_equal(vec4i[3], 4);
}



CPHINX_TEST(vectorN_ctor_array) {
	stx::vectorN<float, 4> vec4f = std::to_array<float>({1,2,3,4});
	cphinx.assert_equal(vec4f[0], 1.f);
	cphinx.assert_equal(vec4f[1], 2.f);
	cphinx.assert_equal(vec4f[2], 3.f);
	cphinx.assert_equal(vec4f[3], 4.f);

	stx::vectorN<int, 4> vec4i = std::to_array<int>({1,2,3,4});
	cphinx.assert_equal(vec4i[0], 1);
	cphinx.assert_equal(vec4i[1], 2);
	cphinx.assert_equal(vec4i[2], 3);
	cphinx.assert_equal(vec4i[3], 4);
}



CPHINX_TEST(vectorN_add) {
	stx::vectorN<float, 7> l = {1,2,3,4,5,6,7};
	stx::vectorN<float, 7> r = {7,6,5,4,3,2,1};

	cphinx.assert_equal(l+r, stx::vectorN<float, 7>{8,8,8,8,8,8,8});
}



CPHINX_TEST(vectorN_sub) {
	stx::vectorN<float, 7> l = {1,2,3,4,5,6,7};
	stx::vectorN<float, 7> r = {7,6,5,4,3,2,1};

	cphinx.assert_equal(l-r, stx::vectorN<float, 7>{-6,-4,-2,0,2,4,6});
}


CPHINX_TEST(vectorN_mlt) {
	stx::vectorN<float, 7> l = {1,2,3,4,5,6,7};
	stx::vectorN<float, 7> r = {2,2,2,2,2,2,2};

	cphinx.assert_equal(l*r, stx::vectorN<float, 7>{2,4,6,8,10,12,14});
}



CPHINX_TEST(vector_scalar_mlt) {
	stx::vectorN<float, 7> v = {1,2,3,4,5,6,7};
	cphinx.assert_equal(v * 2.f, stx::vectorN<float, 7>{2,4,6,8,10,12,14});
	cphinx.assert_equal(2.f * v, stx::vectorN<float, 7>{2,4,6,8,10,12,14});
}



CPHINX_TEST(vector_scalar_div) {
	stx::vectorN<float, 7> v = {2,4,6,8,10,12,14};
	cphinx.assert_equal(v / 2.f, stx::vectorN<float, 7>{1,2,3,4,5,6,7});
}