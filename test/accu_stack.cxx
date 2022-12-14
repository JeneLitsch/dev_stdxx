#include "stdxx/accu_stack.hxx"
#include "cphinx/cphinx.hxx"

CPHINX_TEST(accu_stack_init) {
	stx::accu_stack<int> stack{42};
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), 42, err_msg);
}



CPHINX_TEST(accu_stack_init_empty) {
	stx::accu_stack<int> stack{};
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), 0, err_msg);
}



CPHINX_TEST(accu_stack_init_empty_string) {
	stx::accu_stack<std::string> stack;
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), "", err_msg);
}



CPHINX_TEST(accu_stack_init_string) {
	stx::accu_stack<std::string> stack{"Hello World"};
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), "Hello World", err_msg);
}



CPHINX_TEST(accu_stack_init_ptr_nultptr) {
	stx::accu_stack<int *> stack;
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), nullptr, err_msg);
}



CPHINX_TEST(accu_stack_init_ptr) {	
	int x = 5;
	stx::accu_stack<int *> stack{&x};
	const auto err_msg = "Unexpected init value.";
	cphinx.assert_equal(stack.top(), &x, err_msg);
}



CPHINX_TEST(accu_stack_add_int) {
	stx::accu_stack<int> stack;
	
	stack.push(5);
	cphinx.assert_equal(stack.top(), 5);
	
	stack.push(6);
	cphinx.assert_equal(stack.top(), 11);

	stack.push(10);
	cphinx.assert_equal(stack.top(), 21);

	stack.pop();
	cphinx.assert_equal(stack.top(), 11);

	stack.pop();
	cphinx.assert_equal(stack.top(), 5);

	stack.pop();
	cphinx.assert_equal(stack.top(), 0);
}



CPHINX_TEST(accu_stack_sub_int) {
	stx::accu_stack<int, std::deque<int>, std::minus<int>> stack{5};		
	cphinx.assert_equal(stack.top(), 5);
	
	stack.push(6);
	cphinx.assert_equal(stack.top(), -1);

	stack.push(10);
	cphinx.assert_equal(stack.top(), -11);

	stack.pop();
	cphinx.assert_equal(stack.top(), -1);

	stack.pop();
	cphinx.assert_equal(stack.top(), 5);
}



CPHINX_TEST(accu_stack_mlt_int) {
	stx::accu_stack<int, std::deque<int>, std::multiplies<int>> stack{2};		
	
	stack.push(2);
	cphinx.assert_equal(stack.top(), 4);
	
	stack.push(2);
	cphinx.assert_equal(stack.top(), 8);
	
	stack.push(2);
	cphinx.assert_equal(stack.top(), 16);

	stack.push(2);
	cphinx.assert_equal(stack.top(), 32);
}
	


CPHINX_TEST(accu_stack_concat_string) {
	stx::accu_stack<std::string> stack;
	
	stack.push("Hello");
	cphinx.assert_equal(stack.top(), "Hello");
	
	stack.push(" World");
	cphinx.assert_equal(stack.top(), "Hello World");

	stack.emplace("!");
	cphinx.assert_equal(stack.top(), "Hello World!");

	stack.pop();
	cphinx.assert_equal(stack.top(), "Hello World");

	stack.pop();
	cphinx.assert_equal(stack.top(), "Hello");

	stack.pop();
	cphinx.assert_equal(stack.top(), "");

	stack.emplace("Test");
	cphinx.assert_equal(stack.top(), "Test");

	stack.emplace("123");
	cphinx.assert_equal(stack.top(), "Test123");
}



CPHINX_TEST(accu_stack_empty_size) {
	stx::accu_stack<int> stack;
	cphinx.assert_true(stack.empty());
	cphinx.assert_equal(stack.size(), 0);
	
	stack.push(1);
	cphinx.assert_false(stack.empty());
	cphinx.assert_equal(stack.size(), 1);

	stack.pop();
	cphinx.assert_true(stack.empty());
	cphinx.assert_equal(stack.size(), 0);
}



CPHINX_TEST(accu_stack_swap) {
	stx::accu_stack<int> stack_a{42};
	stx::accu_stack<int> stack_b{1330};

	cphinx.assert_equal(stack_a.top(), 42);
	cphinx.assert_equal(stack_b.top(), 1330);

	std::swap(stack_a, stack_b);

	cphinx.assert_equal(stack_a.top(), 1330);
	cphinx.assert_equal(stack_b.top(), 42);

	stack_a.push(7);
	std::swap(stack_a, stack_b);

	cphinx.assert_equal(stack_a.top(), 42);
	cphinx.assert_equal(stack_b.top(), 1337);
}