#include "accu_stack.hxx"
#include <iostream>
#include "cphinx/cphinx.hxx"

int main() {
	cphinx::cphinx framework;
	framework.run(test::accu_stack_init, "stx::accu_stack init value");
	framework.run(test::accu_stack_top_push_pop, "stx::accu_stack top push and pop");
	framework.run(test::accu_stack_empty_size, "stx::accu_stack empty and size");
	framework.dignostics(std::cout);
	return 0;
}


// #include "cphinx/cphinx.hxx"
// #include <iostream>

// int add(int a, int b) {
// 	return a + b;
// }

// void simple_test(cphinx::validator & validator) {
// 	validator.assert_equal(add(1, 3), 4, "Addition failed");
// 	validator.assert_false(false, "Wrong boolean");
// 	validator.assert_true(true);
// }

// void failing_test(cphinx::validator & validator) {
// 	validator.assert_true(false);
// }

// int main() {
// 	cphinx::cphinx framework;
// 	framework.run(simple_test, "Simple test");
// 	framework.run(failing_test, "Failing test");
// 	framework.dignostics(std::cout);
// 	return 0;
// }