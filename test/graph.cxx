#include "proto/graph.hxx"
#include "cphinx/cphinx.hxx"

struct Node {
	int data;
	bool operator==(const Node &) const = default;
	bool operator<=>(const Node &) const = default;
};



CPHINX_TEST(graph_empty) {
	stx::graph<Node> graph;
	cphinx.assert_equal(graph.size(), 0);
	cphinx.assert_equal(std::size(graph), 0);
	cphinx.assert_true(graph.empty());
	cphinx.assert_true(std::empty(graph));
}



CPHINX_TEST(graph_insert_r_value) {
	stx::graph<Node> graph;
	auto it_a = graph.insert(Node{1});
	auto it_b = graph.insert(Node{2});

	cphinx.assert_equal(graph.size(), 2);
	cphinx.assert_equal(std::size(graph), 2);
	cphinx.assert_false(graph.empty());
	cphinx.assert_false(std::empty(graph));

	cphinx.assert_equal(it_a->data, 1);
	cphinx.assert_equal(it_b->data, 2);
}



CPHINX_TEST(graph_insert_l_value) {
	stx::graph<Node> graph;
	Node a{1};
	Node b{2};
	auto it_a = graph.insert(a);
	auto it_b = graph.insert(b);

	cphinx.assert_equal(graph.size(), 2);
	cphinx.assert_equal(std::size(graph), 2);
	cphinx.assert_false(graph.empty());
	cphinx.assert_false(std::empty(graph));

	cphinx.assert_equal(it_a->data, 1);
	cphinx.assert_equal(it_b->data, 2);
}



CPHINX_TEST(graph_find) {
	stx::graph<Node> graph;
	graph.insert(Node{42});
	cphinx.assert_true(graph.find(Node{42}) != std::end(graph));
	cphinx.assert_true(graph.find(Node{43}) == std::end(graph));
	cphinx.assert_equal(graph.find(Node{42})->data, 42);
}



CPHINX_TEST(graph_find_const) {
	stx::graph<Node> graph;
	const auto & graph_ref = graph;
	graph.insert(Node{42});
	cphinx.assert_true(graph_ref.find(Node{42}) != std::end(graph_ref));
	cphinx.assert_true(graph_ref.find(Node{43}) == std::end(graph_ref));
	cphinx.assert_equal(graph_ref.find(Node{42})->data, 42);
}



CPHINX_TEST(graph_range_empty) {
	stx::graph<Node> graph;
	auto begin = std::begin(graph);
	auto end = std::end(graph);
	cphinx.assert_true(begin == end);
	cphinx.assert_equal(std::distance(begin, end), 0);
}



CPHINX_TEST(graph_for) {
	stx::graph<Node> graph;
	graph.insert(Node{1});
	graph.insert(Node{2});
	graph.insert(Node{3});

	std::size_t counter = 0;
	for(const auto & node : graph) {
		++counter;
	}
	cphinx.assert_equal(counter, std::size(graph));
}



CPHINX_TEST(graph_for_const) {
	stx::graph<Node> graph;
	graph.insert(Node{1});
	graph.insert(Node{2});
	graph.insert(Node{3});

	std::size_t counter = 0;
	for(const auto & node : std::as_const(graph)) {
		++counter;
	}
	cphinx.assert_equal(counter, std::size(graph));
}