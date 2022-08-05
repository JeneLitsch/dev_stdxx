#include "stdxx/accu_stack.hxx"
#include "accu_stack.hxx"

namespace test {
	void accu_stack_init(cphinx::validator & validator) {
		const auto err_msg = "Unexpected init value.";
		
		{
			stx::accu_stack<int> stack{42};
			validator.assert_equal(stack.top(), 42, err_msg);
		}

		{
			stx::accu_stack<int> stack{};
			validator.assert_equal(stack.top(), 0, err_msg);
		}

		{
			stx::accu_stack<std::string> stack;
			validator.assert_equal(stack.top(), "", err_msg);
		}

		{
			stx::accu_stack<std::string> stack{"Hello World"};
			validator.assert_equal(stack.top(), "Hello World", err_msg);
		}

		{
			stx::accu_stack<std::vector<int>> stack;
			validator.assert_equal(stack.top(), std::vector<int>{}, err_msg);
		}

		{
			stx::accu_stack<std::string> stack{"Hello World"};
			validator.assert_equal(stack.top(), "Hello World", err_msg);
		}

		{
			stx::accu_stack<int *> stack;
			validator.assert_equal(stack.top(), nullptr, err_msg);
		}

		{	
			int x = 5;
			stx::accu_stack<int *> stack{&x};
			validator.assert_equal(stack.top(), &x, err_msg);
		}
	}



	void accu_stack_top_push_pop_emplace(cphinx::validator & validator) {
		{
			stx::accu_stack<int> stack;
			
			stack.push(5);
			validator.assert_equal(stack.top(), 5);
			
			stack.push(6);
			validator.assert_equal(stack.top(), 11);

			stack.push(10);
			validator.assert_equal(stack.top(), 21);

			stack.pop();
			validator.assert_equal(stack.top(), 11);
		
			stack.pop();
			validator.assert_equal(stack.top(), 5);

			stack.pop();
			validator.assert_equal(stack.top(), 0);
		}

		{

			stx::accu_stack<int, std::deque<int>, std::minus<int>> stack{5};		
			validator.assert_equal(stack.top(), 5);
			
			stack.push(6);
			validator.assert_equal(stack.top(), -1);

			stack.push(10);
			validator.assert_equal(stack.top(), -11);

			stack.pop();
			validator.assert_equal(stack.top(), -1);
		
			stack.pop();
			validator.assert_equal(stack.top(), 5);
		}

		{
			stx::accu_stack<int, std::deque<int>, std::multiplies<int>> stack{2};		
			
			stack.push(2);
			validator.assert_equal(stack.top(), 4);
			
			stack.push(2);
			validator.assert_equal(stack.top(), 8);
			
			stack.push(2);
			validator.assert_equal(stack.top(), 16);

			stack.push(2);
			validator.assert_equal(stack.top(), 32);
		}
		
		{
			stx::accu_stack<std::string> stack;
			
			stack.push("Hello");
			validator.assert_equal(stack.top(), "Hello");
			
			stack.push(" World");
			validator.assert_equal(stack.top(), "Hello World");

			stack.emplace("!");
			validator.assert_equal(stack.top(), "Hello World!");

			stack.pop();
			validator.assert_equal(stack.top(), "Hello World");
		
			stack.pop();
			validator.assert_equal(stack.top(), "Hello");

			stack.pop();
			validator.assert_equal(stack.top(), "");

			stack.emplace("Test");
			validator.assert_equal(stack.top(), "Test");

			stack.emplace("123");
			validator.assert_equal(stack.top(), "Test123");
		}
	}



	void accu_stack_empty_size(cphinx::validator & validator) {
		{
			stx::accu_stack<int> stack;
			validator.assert_true(stack.empty());
			validator.assert_equal(stack.size(), 0);
			
			stack.push(1);
			validator.assert_false(stack.empty());
			validator.assert_equal(stack.size(), 1);

			stack.pop();
			validator.assert_true(stack.empty());
			validator.assert_equal(stack.size(), 0);
		}
	}



	void accu_stack_swap(cphinx::validator & validator) {
		{
			stx::accu_stack<int> stack_a{42};
			stx::accu_stack<int> stack_b{1330};

			validator.assert_equal(stack_a.top(), 42);
			validator.assert_equal(stack_b.top(), 1330);

			std::swap(stack_a, stack_b);

			validator.assert_equal(stack_a.top(), 1330);
			validator.assert_equal(stack_b.top(), 42);

			stack_a.push(7);
			std::swap(stack_a, stack_b);

			validator.assert_equal(stack_a.top(), 42);
			validator.assert_equal(stack_b.top(), 1337);
		}
	}
}