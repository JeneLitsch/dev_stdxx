#include <array>
#include "cphinx/cphinx.hxx"
#include "proto/optref.hxx"
namespace {
	struct S {
		int i = 5;
	};
}



CPHINX_TEST(optref_null) {
	stx::optref<int> a = std::nullopt;
	stx::optref<int> b = nullptr;
	stx::optref<int> c;
	stx::optref<int> d = stx::nullref;
	cphinx.assert_false(a, "Null optref must evaluate to false");
	cphinx.assert_false(b, "Null optref must evaluate to false");
	cphinx.assert_false(c, "Null optref must evaluate to false");
	cphinx.assert_false(d, "Null optref must evaluate to false");
}



CPHINX_TEST(optref_non_null) {
	int i = 5;
	stx::optref<int> r = i;
	cphinx.assert_true(r, "Non-null optref must evaluate to true");
	cphinx.assert_equal(*r, 5, "Must be same as i");
	cphinx.assert_equal(*(&r), 5, "Must be same as i");
}



CPHINX_TEST(optref_value) {
	int i = 5;
	stx::optref<int> r = i;
	cphinx.assert_true(r, "Non-null optref must evaluate to true");
	cphinx.assert_equal(r.value(), 5, "Must be same as i");
}



CPHINX_TEST(optref_value_or) {
	int i1 = 42;
	int i2 = 1337;
	stx::optref<int> r1 = i1;
	stx::optref<int> r2;
	cphinx.assert_equal(r1.value_or(i2), 42, "Must be same as i1");
	cphinx.assert_equal(r2.value_or(i2), 1337, "Must be same as i2");
}



CPHINX_TEST(optref_member_access) {
	S s;
	stx::optref<S> r = s;
	r->i = 42;
	cphinx.assert_equal(s.i, 42, "The member i of the original struct must be changed");
	cphinx.assert_equal(r->i, 42, "The member i of the referenced struct must be changed");
}



CPHINX_TEST(optref_ref_assign) {
	S s1 { .i = 42   };
	S s2 { .i = 1337 };

	stx::optref<S> r = s1;
	cphinx.assert_equal(r->i, 42, "Must reference s1");
	r = s2;
	cphinx.assert_equal(r->i, 1337, "Must reference s2");
}



CPHINX_TEST(optref_val_assign) {
	S s1 { .i = 42   };
	S s2 { .i = 1337 };

	stx::optref<S> r = s1;
	*r = s2;
	cphinx.assert_equal(s1.i, s2.i, "s2.i must be == to s1.i");
}



CPHINX_TEST(optref_equal) {
	int a = 42;
	int b = 42;

	stx::optref<int> r1 = a;
	stx::optref<int> r2 = b;
	stx::optref<int> r3 = a;

	cphinx.assert_true(r1 == r3);
	cphinx.assert_false(r1 == r2);
	cphinx.assert_false(r3 == r2);

	cphinx.assert_false(r1 != r3);
	cphinx.assert_true(r1 != r2);
	cphinx.assert_true(r3 != r2);

	cphinx.assert_true(&r1 == &a);
}


const std::array<int, 3> a = {1,2,3};

const stx::optref<const int> r1 = a[0];
const stx::optref<const int> r2 = a[1];
const stx::optref<const int> r3 = a[2];

CPHINX_TEST(optref_compare_lt) {

	cphinx.assert_equal(r1 < r1, false);
	cphinx.assert_equal(r1 < r2, true);
	cphinx.assert_equal(r1 < r3, true);

	cphinx.assert_equal(r2 < r1, false);
	cphinx.assert_equal(r2 < r2, false);
	cphinx.assert_equal(r2 < r3, true);
	
	cphinx.assert_equal(r3 < r1, false);
	cphinx.assert_equal(r3 < r2, false);
	cphinx.assert_equal(r3 < r3, false);
}



CPHINX_TEST(optref_compare_lteq) {
	cphinx.assert_equal(r1 <= r1, true);
	cphinx.assert_equal(r1 <= r2, true);
	cphinx.assert_equal(r1 <= r3, true);

	cphinx.assert_equal(r2 <= r1, false);
	cphinx.assert_equal(r2 <= r2, true);
	cphinx.assert_equal(r2 <= r3, true);

	cphinx.assert_equal(r3 <= r1, false);
	cphinx.assert_equal(r3 <= r2, false);
	cphinx.assert_equal(r3 <= r3, true);
}



CPHINX_TEST(optref_compare_gt) {

	cphinx.assert_equal(r1 > r1, false);
	cphinx.assert_equal(r1 > r2, false);
	cphinx.assert_equal(r1 > r3, false);

	cphinx.assert_equal(r2 > r1, true);
	cphinx.assert_equal(r2 > r2, false);
	cphinx.assert_equal(r2 > r3, false);
	
	cphinx.assert_equal(r3 > r1, true);
	cphinx.assert_equal(r3 > r2, true);
	cphinx.assert_equal(r3 > r3, false);
}



CPHINX_TEST(optref_compare_gteq) {
	cphinx.assert_equal(r1 >= r1, true);
	cphinx.assert_equal(r1 >= r2, false);
	cphinx.assert_equal(r1 >= r3, false);

	cphinx.assert_equal(r2 >= r1, true);
	cphinx.assert_equal(r2 >= r2, true);
	cphinx.assert_equal(r2 >= r3, false);

	cphinx.assert_equal(r3 >= r1, true);
	cphinx.assert_equal(r3 >= r2, true);
	cphinx.assert_equal(r3 >= r3, true);
}