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



	void accu_stack_top_push_pop(cphinx::validator & validator) {
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
			stx::accu_stack<std::string> stack;
			
			stack.push("Hello");
			validator.assert_equal(stack.top(), "Hello");
			
			stack.push(" World");
			validator.assert_equal(stack.top(), "Hello World");

			stack.push("!");
			validator.assert_equal(stack.top(), "Hello World!");

			stack.pop();
			validator.assert_equal(stack.top(), "Hello World");
		
			stack.pop();
			validator.assert_equal(stack.top(), "Hello");

			stack.pop();
			validator.assert_equal(stack.top(), "");
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
}