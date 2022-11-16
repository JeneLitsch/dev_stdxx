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


CPHINX_TEST(vector2_ctor_float) {
	constexpr static stx::vector2f vec {-1,2};
	cphinx.assert_equal(vec.x, -1, "Invalid x");
	cphinx.assert_equal(vec.y,  2, "Invalid y");
}



CPHINX_TEST(vector2_ctor_int) {
	const stx::vector2i vec {42};
	cphinx.assert_equal(vec.x, 42, "Invalid x");
	cphinx.assert_equal(vec.y, 42, "Invalid y");
}


CPHINX_TEST(vector2_index) {
	constexpr static stx::vector2f vec {-1,2};
	cphinx.assert_equal(vec[0], -1, "Invalid x");
	cphinx.assert_equal(vec[1],  2, "Invalid y");
	cphinx.assert_true(is_successful([&] { vec[0]; }));
	cphinx.assert_true(is_successful([&] { vec[1]; }));
	cphinx.assert_false(is_successful([&] { vec[2]; }));
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

	const stx::vector2f c = b / 2.f;
	cphinx.assert_equal(c, stx::vector2f{2, 4}, "Invalid vector");
}



CPHINX_TEST(vector2_scalar_int) {
	const stx::vector2i a {1, 2};
	cphinx.assert_equal(a, stx::vector2i{1, 2}, "Invalid vector");

	const stx::vector2i b = a * 4;
	cphinx.assert_equal(b, stx::vector2i{4, 8}, "Invalid vector");

	const stx::vector2i c = b / 2;
	cphinx.assert_equal(c, stx::vector2i{2, 4}, "Invalid vector");
}



CPHINX_TEST(vector2_unary_float) {
	const stx::vector2f a {1.5, 2};
	cphinx.assert_equal(a, stx::vector2f{1.5, 2}, "Invalid vector");

	const stx::vector2f b = -a;
	cphinx.assert_equal(b, stx::vector2f{-1.5, -2}, "Invalid vector");
	
	const stx::vector2f c = -b;
	cphinx.assert_equal(c, stx::vector2f{1.5, 2}, "Invalid vector");
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