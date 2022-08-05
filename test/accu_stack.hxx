#pragma once
#include "cphinx/cphinx.hxx"

namespace test {
	void accu_stack_init(cphinx::validator & validator);
	void accu_stack_top_push_pop_emplace(cphinx::validator & validator);
	void accu_stack_empty_size(cphinx::validator & validator);
	void accu_stack_swap(cphinx::validator & validator);
}