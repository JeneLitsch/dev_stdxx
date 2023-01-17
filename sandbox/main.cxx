#include <vector>
#include <iostream>
#include "proto/enumerate.hxx"
#include "proto/zip.hxx"
#include "proto/graph.hxx"


int main() {
	stx::adjacency_list adj_list;
	adj_list.link(1, 2);
	adj_list.link(1, 3);
	adj_list.link(2, 3);
	adj_list.link(3, 3);

	std::cout << adj_list.is_adjacent(1,2) << "\n";
	std::cout << adj_list.is_adjacent(1,3) << "\n";
	std::cout << adj_list.is_adjacent(2,3) << "\n";
	std::cout << adj_list.is_adjacent(3,3) << "\n";
	std::cout << adj_list.is_adjacent(4,2) << "\n";
	std::cout << adj_list.is_adjacent(4,3) << "\n";
	std::cout << adj_list.is_adjacent(4,3) << "\n";
	std::cout << adj_list.is_adjacent(4,3) << "\n";
}
