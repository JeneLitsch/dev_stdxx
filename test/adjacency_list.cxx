#include "proto/graph.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(adjacency_list_empty) {
	stx::adjacency_list adj_list;
	cphinx.assert_false(adj_list.is_adjacent(42, 1337));
	cphinx.assert_false(adj_list.is_adjacent(1, 1));
	cphinx.assert_false(adj_list.is_adjacent(3, 2));
}



CPHINX_TEST(adjacency_list_link) {
	stx::adjacency_list adj_list;
	adj_list.link(0,1);
	cphinx.assert_true(adj_list.is_adjacent(0, 1));
	cphinx.assert_false(adj_list.is_adjacent(1, 0));
	cphinx.assert_false(adj_list.is_adjacent(0, 2));
}



CPHINX_TEST(adjacency_list_unlink) {
	stx::adjacency_list adj_list;
	adj_list.link(0,1);
	adj_list.link(0,2);
	adj_list.unlink(0,1);
	cphinx.assert_false(adj_list.is_adjacent(0, 1));
	cphinx.assert_true(adj_list.is_adjacent(0, 2));
}