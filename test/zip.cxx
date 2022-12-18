#include "proto/zip.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(zip_vector) {
	const auto zipped1 = stx::fx::zip(
		std::vector<int>{},
		std::vector<int>{},
		std::vector<int>{}
	);
	cphinx.assert_equal(zipped1, decltype(zipped1){});


	const auto zipped2 = stx::fx::zip(
		std::vector{1,2,3},
		std::vector{1,2,3},
		std::vector{1,2,3}
	);
	cphinx.assert_equal(zipped2, decltype(zipped2) {
		 {1,1,1},
		 {2,2,2},
		 {3,3,3},
	});


	const auto zipped3 = stx::fx::zip(
		std::vector{1,2,3},
		std::vector{1,2,3,4},
		std::vector{1,2,3,4,5}
	);
	cphinx.assert_equal(zipped3, decltype(zipped3) {
		 {1,1,1},
		 {2,2,2},
		 {3,3,3},
	});


	const auto zipped4 = stx::fx::zip(
		std::vector{1, 2, 3},
		std::vector{10.f, 20.f, 30.f}
	);
	cphinx.assert_equal(zipped4, decltype(zipped4){
		{1, 10.f},
		{2, 20.f},
		{3, 30.f}
	});
}



CPHINX_TEST(zip_vm_vector) {
	const auto zipped1 = stx::fx::zip_mv(
		std::vector<int>{},
		std::vector<int>{},
		std::vector<int>{}
	);
	cphinx.assert_equal(zipped1, decltype(zipped1){});


	const auto zipped2 = stx::fx::zip_mv(
		std::vector{1,2,3},
		std::vector{1,2,3},
		std::vector{1,2,3}
	);
	cphinx.assert_equal(zipped2, decltype(zipped2) {
		 {1,1,1},
		 {2,2,2},
		 {3,3,3},
	});


	const auto zipped3 = stx::fx::zip_mv(
		std::vector{1,2,3},
		std::vector{1,2,3,4},
		std::vector{1,2,3,4,5}
	);
	cphinx.assert_equal(zipped3, decltype(zipped3) {
		 {1,1,1},
		 {2,2,2},
		 {3,3,3},
	});


	const auto zipped4 = stx::fx::zip_mv(
		std::vector{1, 2, 3},
		std::vector{10.f, 20.f, 30.f}
	);
	cphinx.assert_equal(zipped4, decltype(zipped4){
		{1, 10.f},
		{2, 20.f},
		{3, 30.f}
	});
}




CPHINX_TEST(unzip_vector) {
	std::vector<std::tuple<int, float>> zipped {
		{1, 10.f},
		{2, 20.f},
		{3, 30.f}
	};

	const auto [vec_int, vec_float] = stx::fx::unzip(zipped);
	cphinx.assert_equal(vec_int, decltype(vec_int) {1,2,3});
	cphinx.assert_equal(vec_float, decltype(vec_float) {10.f,20.f,30.f});
}