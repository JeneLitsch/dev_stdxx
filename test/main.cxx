#include "accu_stack.hxx"
#include <iostream>

int main() {
	cphinx::cphinx framework;
	framework.run(test::accu_stack_init, "stx::accu_stack init value");
	framework.run(test::accu_stack_top_push_pop, "stx::accu_stack top push and pop");
	framework.dignostics(std::cout);
	return 0;
}
