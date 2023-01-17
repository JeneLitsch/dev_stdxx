#pragma once
#include <unordered_map>
#include <set>
#include <optional>
#include <vector>
#include <cstdint>
#include <iterator>

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



	template<typename Node, typename AdjacencyDescriptor = adjacency_list>
	class graph {
		template<typename NodeT, typename GraphT>
		struct basic_iterator {
		public:
			using iterator_category = std::input_iterator_tag;
			using value_type = NodeT;
			using pointer = value_type *;
			using reference = value_type &;
			using difference_type = std::uint64_t;

			basic_iterator(GraphT * graph, std::size_t index)
				: graph{graph}
				, index{index} {}

			NodeT & operator*() const {
				return graph->nodes[index];
			}

			NodeT * operator->() const {
				return &graph->nodes[index];
			}

			friend bool operator==(
				const basic_iterator & l,
				const basic_iterator & r) {
				
				if(l.graph != r.graph) return false;
				else return l.index == r.index;
			}

			basic_iterator & operator++() {
				this->index++;
				return *this;
			}

			basic_iterator & operator--() {
				this->index--;
				return *this;
			}

			basic_iterator & operator++(int) {
				auto old = *this;
				(*this)++;
				return old;
			}

			basic_iterator & operator--(int) {
				auto old = *this;
				(*this)--;
				return old;
			}

		private:
			std::size_t index;
			GraphT * graph;
		};

	public:

		using iterator = basic_iterator<Node, graph<Node>>;
		using const_iterator = basic_iterator<const Node, const graph<Node>>;
		


		iterator insert(Node && node) {
			const auto index = nodes.size(); 
			nodes.push_back(std::move(node));
			return iterator{this, index};
		}



		iterator insert(const Node & node) {
			return this->insert(Node{node});
		}



		std::size_t size() const {
			return std::size(this->nodes);
		}



		bool empty() const {
			return std::empty(this->nodes);
		}



		const_iterator find(const Node & node) const {
			auto index = find_impl(node);
			return index ? const_iterator{this, *index} : this->end(); 
		}



		iterator find(const Node & node) {
			auto index = find_impl(node);
			return index ? iterator{this, *index} : this->end(); 
		}


		iterator begin() {
			return {this, 0};
		}

		iterator end() {
			return {this, this->size()};
		}

		const_iterator begin() const {
			return {this, 0};
		}

		const_iterator end() const {
			return {this, this->size()};
		}

	private:
		std::optional<std::size_t> find_impl(const Node & node) const {
			auto begin = std::begin(this->nodes);
			auto end = std::end(this->nodes);
			auto it = std::find(begin, end, node);
			if(it == end) return std::nullopt;
			else return static_cast<std::size_t>(std::distance(begin, it));
		}
		std::vector<Node> nodes;
		AdjacencyDescriptor adj;	
	};
}