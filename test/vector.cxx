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

CPHINX_TEST(vector_by_index) {
	constexpr static stx::vector2f vec {-1,2};
	cphinx.assert_equal(vec[0], -1, "Invalid x");
	cphinx.assert_equal(vec[1],  2, "Invalid y");
	cphinx.assert_true(is_successful([&] { vec[0]; }));
	cphinx.assert_true(is_successful([&] { vec[1]; }));
	cphinx.assert_false(is_successful([&] { vec[2]; }));

	constexpr static stx::vector3f v3 {-1,2,-3};
	cphinx.assert_equal(v3[0], -1, "Invalid x");
	cphinx.assert_equal(v3[1],  2, "Invalid y");
	cphinx.assert_equal(v3[2], -3, "Invalid z");
	cphinx.assert_true(is_successful([&] { v3[0]; }));
	cphinx.assert_true(is_successful([&] { v3[1]; }));
	cphinx.assert_true(is_successful([&] { v3[2]; }));
	cphinx.assert_false(is_successful([&] { v3[3]; }));

	stx::vectorN<float, 4> vec4a = {1,2,3,4};
	cphinx.assert_equal(vec4a[0], 1.f);
	cphinx.assert_equal(vec4a[1], 2.f);
	cphinx.assert_equal(vec4a[2], 3.f);
	cphinx.assert_equal(vec4a[3], 4.f);

	stx::vectorN<int, 4> vec4b {1,2,3,4};
	cphinx.assert_equal(vec4b[0], 1);
	cphinx.assert_equal(vec4b[1], 2);
	cphinx.assert_equal(vec4b[2], 3);
	cphinx.assert_equal(vec4b[3], 4);
}



CPHINX_TEST(vector_by_axis) {
	constexpr static stx::vector2f vec_a {-1,2};
	cphinx.assert_equal(vec_a.x, -1, "Invalid x");
	cphinx.assert_equal(vec_a.y,  2, "Invalid y");
	
	const stx::vector2i vec_b {42};
	cphinx.assert_equal(vec_b.x, 42, "Invalid x");
	cphinx.assert_equal(vec_b.y, 42, "Invalid y");
}



CPHINX_TEST(vectorN_ctor_default) {
	stx::vectorN<float, 4> vec4a;
	cphinx.assert_equal(vec4a[0], 0.f);
	cphinx.assert_equal(vec4a[1], 0.f);
	cphinx.assert_equal(vec4a[2], 0.f);
	cphinx.assert_equal(vec4a[3], 0.f);

	stx::vectorN<int, 4> vec4b;
	cphinx.assert_equal(vec4b[0], 0);
	cphinx.assert_equal(vec4b[1], 0);
	cphinx.assert_equal(vec4b[2], 0);
	cphinx.assert_equal(vec4b[3], 0);
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
	stx::vector2f v2 {1,2};
	cphinx.assert_equal(v2 * 2.f, stx::vector2f{2,4});
	cphinx.assert_equal(2.f * v2, stx::vector2f{2,4});

	stx::vector3<float> v3 {1,2,3};
	cphinx.assert_equal(v3 * 2.f, stx::vector3f{2,4,6});
	cphinx.assert_equal(2.f * v3, stx::vector3f{2,4,6});

	stx::vectorN<float, 7> v7 = {1,2,3,4,5,6,7};
	cphinx.assert_equal(v7 * 2.f, stx::vectorN<float, 7>{2,4,6,8,10,12,14});
	cphinx.assert_equal(2.f * v7, stx::vectorN<float, 7>{2,4,6,8,10,12,14});
}



CPHINX_TEST(vector_scalar_div) {
	const stx::vector2i v2 {2, 4};
	cphinx.assert_equal(v2 / 2, stx::vector2i{1, 2}, "Invalid vector");

	const stx::vector3i v3 {2, 4, 6};
	cphinx.assert_equal(v3 / 2, stx::vector3i{1, 2, 3}, "Invalid vector");

	stx::vectorN<float, 7> v7 = {2,4,6,8,10,12,14};
	cphinx.assert_equal(v7 / 2.f, stx::vectorN<float, 7>{1,2,3,4,5,6,7});
}



CPHINX_TEST(vector2_ctor_unsigned) {
	stx::vector2ul vec;
	cphinx.assert_equal(vec.x, 0, "Invalid x");
	cphinx.assert_equal(vec.y, 0, "Invalid y");
}



CPHINX_TEST(vector2_copy_ctor) {
	const stx::vector2i vec {42};
	const stx::vector2i vec2 {vec};
	cphinx.assert_equal(vec2.x, 42, "Invalid x");
	cphinx.assert_equal(vec2.y, 42, "Invalid y");
}



CPHINX_TEST(vector2_ostream_float) {
	std::ostringstream oss;
	oss << stx::vector2f{1,1} << stx::vector2f{1,-42};

	cphinx.assert_equal(oss.str(), "(1, 1)(1, -42)");
}



CPHINX_TEST(vector2_equal_float) {
	cphinx.assert_true(stx::vector2f{1,1} == stx::vector2f{1,1});
	cphinx.assert_true(stx::vector2f{1,-1.5} == stx::vector2f{1,-1.5});
	cphinx.assert_false(stx::vector2f{42,-1.5} == stx::vector2f{1,-1.5});
}



CPHINX_TEST(vector2_unequal_float) {
	cphinx.assert_false(stx::vector2f{1,1} != stx::vector2f{1,1});
	cphinx.assert_false(stx::vector2f{1,-1.5} != stx::vector2f{1,-1.5});
	cphinx.assert_true(stx::vector2f{42,-1.5} != stx::vector2f{1,-1.5});
}


CPHINX_TEST(vector2_elementwise_float) {
	const stx::vector2f a;
	cphinx.assert_equal(a, stx::vector2f{0,0}, "Invalid vector");
	
	const stx::vector2f b = a + stx::vector2f {10, 42};			
	cphinx.assert_equal(b, stx::vector2f{10,42}, "Invalid vector");

	const stx::vector2f c = b - stx::vector2f {20, 32};
	cphinx.assert_equal(c, stx::vector2f{-10, 10}, "Invalid vector");

	const stx::vector2f d = c * stx::vector2f {2, 2};
	cphinx.assert_equal(d, stx::vector2f{-20, 20}, "Invalid vector");

	const stx::vector2f e = d / stx::vector2f {4, 4};
	cphinx.assert_equal(e, stx::vector2f{-5, 5}, "Invalid vector");
}



CPHINX_TEST(vector2_elementwise_int) {
	const stx::vector2i a;
	cphinx.assert_equal(a, stx::vector2i{0,0}, "Invalid vector");
	
	const stx::vector2i b = a + stx::vector2i {10, 42};			
	cphinx.assert_equal(b, stx::vector2i{10,42}, "Invalid vector");

	const stx::vector2i c = b - stx::vector2i {20, 32};
	cphinx.assert_equal(c, stx::vector2i{-10, 10}, "Invalid vector");

	const stx::vector2i d = c * stx::vector2i {2, 2};
	cphinx.assert_equal(d, stx::vector2i{-20, 20}, "Invalid vector");

	const stx::vector2i e = d / stx::vector2i {4, 4};
	cphinx.assert_equal(e, stx::vector2i{-5, 5}, "Invalid vector");
}



CPHINX_TEST(vector2_scalar_float) {
	const stx::vector2f a {1, 2};
	cphinx.assert_equal(a, stx::vector2f{1, 2}, "Invalid vector");

	const stx::vector2f b = a * 4.f;
	cphinx.assert_equal(b, stx::vector2f{4, 8}, "Invalid vector");


}




CPHINX_TEST(vector2_unary_float) {
	const stx::vector2f v {1.5, 2};
	cphinx.assert_equal(v, stx::vector2f{1.5, 2}, "Invalid vector");
	cphinx.assert_equal(-v, stx::vector2f{-1.5, -2}, "Invalid vector");
	cphinx.assert_equal(-(-v), stx::vector2f{1.5, 2}, "Invalid vector");
} 



CPHINX_TEST(vector2_unary_int) {
	const stx::vector2i a {1, 2};
	cphinx.assert_equal(a, stx::vector2i{1, 2}, "Invalid vector");

	const stx::vector2i b = -a;
	cphinx.assert_equal(b, stx::vector2i{-1, -2}, "Invalid vector");
	
	const stx::vector2i c = -b;
	cphinx.assert_equal(c, stx::vector2i{1, 2}, "Invalid vector");
}



CPHINX_TEST(vector2_dot_float) {
	const auto run = [&] (auto vec1, auto vec2, auto result) {
		cphinx.assert_equal(stx::dot(vec1, vec2), result, "Invalid dot");
	};

	run(stx::vector2f{0, 0}, stx::vector2f{0, 0}, 0);
	run(stx::vector2f{1, 0}, stx::vector2f{1, 0}, 1);
	run(stx::vector2f{1, 0}, stx::vector2f{0, 1}, 0);
	run(stx::vector2f{1, 0}, stx::vector2f{-1, 0}, -1);
	run(stx::vector2f{1, 2}, stx::vector2f{1, 2}, 5);
	run(stx::vector2f{-2, 1}, stx::vector2f{1, 2}, 0);
	run(stx::vector2f{-1, -2}, stx::vector2f{1, 2}, -5);
} 



CPHINX_TEST(vector2_dot_int) {
	const auto run = [&] (auto vec1, auto vec2, auto result) {
		cphinx.assert_equal(stx::dot(vec1, vec2), result, "Invalid dot");
	};

	run(stx::vector2i{1, 2}, stx::vector2i{1, 2}, 5);
	run(stx::vector2i{-2, 1}, stx::vector2i{1, 2}, 0);
	run(stx::vector2i{-1, -2}, stx::vector2i{1, 2}, -5);
} 



CPHINX_TEST(vector2_hypot_float) {
	const auto run = [&] (auto vec, auto result) {
		cphinx.assert_equal(stx::hypot(vec), result, "Invalid hypot");
	};

	run(stx::vector2f{0, 0}, 0);
	run(stx::vector2f{3, 0}, 3);
	run(stx::vector2f{-3, 0}, 3);
	run(stx::vector2f{0, 3}, 3);
	run(stx::vector2f{-3, 0}, 3);
	run(stx::vector2f{3, 4}, 5);
	run(stx::vector2f{-3, 4}, 5);
	run(stx::vector2f{3, -4}, 5);
	run(stx::vector2f{-3, -4}, 5);
} 



CPHINX_TEST(vector2_hypot_int) {
	const auto run = [&] (auto vec, auto result) {
		cphinx.assert_equal(stx::hypot(vec), result, "Invalid hypot");
	};

	run(stx::vector2i{0, 0}, 0);
	run(stx::vector2i{3, 0}, 3);
	run(stx::vector2i{-3, 0}, 3);
	run(stx::vector2i{0, 3}, 3);
	run(stx::vector2i{-3, 0}, 3);
	run(stx::vector2i{3, 4}, 5);
	run(stx::vector2i{-3, 4}, 5);
	run(stx::vector2i{3, -4}, 5);
	run(stx::vector2i{-3, -4}, 5);
}



CPHINX_TEST(vector2_round) {
	const auto run = [&] (stx::vector2f vec, stx::vector2f result) {
		cphinx.assert_equal(stx::round(vec), result, "Invalid rounding");
	};

	run({-1.0f,  1.0f}, {-1.0f,  1.0f});
	run({ 1.5f,  2.1f}, { 2.0f,  2.0f});
	run({-1.2f, -1.7f}, {-1.0f, -2.0f});
	run({-1.2f, -1.5f}, {-1.0f, -2.0f});
}



CPHINX_TEST(vector2_floor) {
	const auto run = [&] (stx::vector2f vec, stx::vector2f result) {
		cphinx.assert_equal(stx::floor(vec), result, "Invalid rounding");
	};

	run({-1.0f,  1.0f}, {-1.0f,  1.0f});
	run({ 1.5f,  2.1f}, { 1.0f,  2.0f});
	run({-1.2f, -1.7f}, {-2.0f, -2.0f});
	run({-1.2f, -1.5f}, {-2.0f, -2.0f});
}



CPHINX_TEST(vector2_ceil) {
	const auto run = [&] (stx::vector2f vec, stx::vector2f result) {
		cphinx.assert_equal(stx::ceil(vec), result, "Invalid rounding");
	};

	run({-1.0f,  1.0f}, {-1.0f,  1.0f});
	run({ 1.5f,  2.1f}, { 2.0f,  3.0f});
	run({-1.2f, -1.7f}, {-1.0f, -1.0f});
	run({-1.2f, -1.5f}, {-1.0f, -1.0f});
}



CPHINX_TEST(vector2_frac_round) {
	const auto run = [&] (stx::vector2f vec, float frac, stx::vector2f result) {
		cphinx.assert_equal(stx::round(vec, frac), result, "Invalid rounding");
	};

	run({-1.0f,  1.0f}, 0.5f, {-1.0f,  1.0f});
	run({ 1.5f,  2.1f}, 0.5f, { 1.5f,  2.0f});
	run({-1.2f, -1.7f}, 0.5f, {-1.0f, -1.5f});
	run({-1.2f, -1.5f}, 0.5f, {-1.0f, -1.5f});
}