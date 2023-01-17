#pragma once
#include <unordered_map>
#include <set>

namespace stx {
	class adjacency_list {
	public:
		bool is_adjacent(std::size_t from, std::size_t to) const {
			return table.contains(from) && table.at(from).contains(to);
		}

		void link(std::size_t from, std::size_t to) {
			table[from].insert(to);
		}

		void unlink(std::size_t from, std::size_t to) {
			if(table.contains(from)) {
				table.at(from).erase(to);
				if(std::empty(table.at(from))) {
					table.erase(from);
				}
			}
		}
	private:
		std::unordered_map<std::size_t, std::set<std::size_t>> table;
	};
}