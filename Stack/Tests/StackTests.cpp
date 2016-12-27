#include "stdafx.h"
#include <string>
#include "../Stack/Stack.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CMyStack_)

struct StackOfInt
{
	CMyStack<int> stack;
};

BOOST_FIXTURE_TEST_SUITE(of_integer, StackOfInt)

BOOST_AUTO_TEST_CASE(is_empty_by_default)
{
	BOOST_CHECK(stack.IsStackEmpty());
}

BOOST_AUTO_TEST_CASE(can_be_constructed_from_other_stack)
{
	stack.Push(97);
	stack.Push(34);
	CMyStack<int> secondStack(stack);
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), stack.GetStackSize());
	BOOST_CHECK_EQUAL(secondStack.GetElement(), stack.GetElement());
}

BOOST_AUTO_TEST_CASE(first_stack_is_independent_of_its_copies)
{
	stack.Push(97);
	stack.Push(34);
	size_t begSize = stack.GetStackSize();
	CMyStack<int> secondStack(stack);
	secondStack.Pop();
	BOOST_CHECK_EQUAL(stack.GetStackSize(), begSize);
}

BOOST_AUTO_TEST_CASE(can_be_moved)
{
	stack.Push(97);
	stack.Push(34);
	CMyStack<int> secondStack = std::move(stack);
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), 2);
}

BOOST_AUTO_TEST_CASE(can_be_assigned)
{
	stack.Push(97);
	stack.Push(34);
	CMyStack<int> secondStack;
	secondStack = stack;
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), stack.GetStackSize());
	BOOST_CHECK_EQUAL(secondStack.GetElement(), stack.GetElement());
	secondStack.Pop();
	BOOST_CHECK(stack.GetStackSize() == 2);
}

BOOST_AUTO_TEST_CASE(can_be_assigned_with_move)
{
	CMyStack<int> secondStack;
	secondStack = CMyStack<int>();
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_SUITE(throw_exception_if)

BOOST_AUTO_TEST_CASE(Pop_from_empty_stack)
{
	BOOST_REQUIRE_THROW(stack.Pop(), std::logic_error);
}
BOOST_AUTO_TEST_CASE(GetElement_from_empty_stack)
{
	BOOST_REQUIRE_THROW(stack.GetElement(), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(can_add_element)
{
	stack.Push(10);
	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
	BOOST_CHECK_EQUAL(stack.GetElement(), 10);
}

struct WithElements : StackOfInt
{
	WithElements()
	{
		stack.Push(10);
		stack.Push(90);
		stack.Push(70);
		stack.Push(40);
		stack.Push(20);
	}
};
BOOST_FIXTURE_TEST_SUITE(with_elements, WithElements)

BOOST_AUTO_TEST_CASE(can_contain_any_elements)
{

	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 5);
}

BOOST_AUTO_TEST_CASE(can_return_last_element)
{
	BOOST_CHECK_EQUAL(stack.GetElement(), 20);
}

BOOST_AUTO_TEST_CASE(can_delete_last_element)
{
	stack.Pop();
	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 4);
	BOOST_CHECK_EQUAL(stack.GetElement(), 40);
}

BOOST_AUTO_TEST_CASE(can_be_cleaned)
{
	stack.Clear();
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

struct StackOfString
{
	CMyStack<std::string> stack;
};
BOOST_FIXTURE_TEST_SUITE(of_string, StackOfString)

BOOST_AUTO_TEST_CASE(is_empty_by_default)
{
	BOOST_CHECK(stack.IsStackEmpty());
}

BOOST_AUTO_TEST_CASE(can_be_constructed_from_other_stack)
{
	stack.Push("abcdef");
	stack.Push("qwerty");
	CMyStack<std::string> secondStack(stack);
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), stack.GetStackSize());
	BOOST_CHECK_EQUAL(secondStack.GetElement(), stack.GetElement());
}

BOOST_AUTO_TEST_CASE(first_stack_is_independent_of_its_copies)
{
	stack.Push("abcdef");
	stack.Push("qwerty");
	size_t oldSize = stack.GetStackSize();
	CMyStack<std::string> secondStack(stack);
	secondStack.Pop();
	BOOST_CHECK_EQUAL(stack.GetStackSize(), oldSize);
}

BOOST_AUTO_TEST_CASE(can_be_moved)
{
	stack.Push("abcdef");
	stack.Push("qwerty");
	CMyStack<std::string> secondStack = std::move(stack);
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), 2);
}

BOOST_AUTO_TEST_CASE(can_be_assigned)
{
	stack.Push("abcdef");
	stack.Push("qwerty");
	CMyStack<std::string> secondStack;
	secondStack = stack;
	BOOST_CHECK_EQUAL(secondStack.GetStackSize(), stack.GetStackSize());
	BOOST_CHECK_EQUAL(secondStack.GetElement(), stack.GetElement());
	secondStack.Pop();
	BOOST_CHECK(stack.GetStackSize() == 2);
}

BOOST_AUTO_TEST_CASE(can_be_assigned_with_move)
{
	CMyStack<std::string> secondStack;
	secondStack = CMyStack<std::string>();
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_SUITE(throw_exception_if)

BOOST_AUTO_TEST_CASE(Pop_from_empty_stack)
{
	BOOST_REQUIRE_THROW(stack.Pop(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(GetElement_from_empty_stack)
{
	BOOST_REQUIRE_THROW(stack.GetElement(), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(can_add_element)
{
	stack.Push("abcdef");
	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
	BOOST_CHECK_EQUAL(stack.GetElement(), "abcdef");
}

struct WithElements : StackOfString
{
	WithElements()
	{
		stack.Push("abcdef");
		stack.Push("");
		stack.Push("qwerty");
		stack.Push("q");
		stack.Push("my stack");
	}
};

BOOST_FIXTURE_TEST_SUITE(with_elements, WithElements)

BOOST_AUTO_TEST_CASE(can_contain_any_elements)
{
	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 5);
}

BOOST_AUTO_TEST_CASE(can_return_last_element)
{
	BOOST_CHECK_EQUAL(stack.GetElement(), "my stack");
}

BOOST_AUTO_TEST_CASE(can_delete_last_element)
{
	stack.Pop();
	BOOST_CHECK(!stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 4);
	BOOST_CHECK_EQUAL(stack.GetElement(), "q");
}

BOOST_AUTO_TEST_CASE(can_be_cleaned)
{
	stack.Clear();
	BOOST_CHECK(stack.IsStackEmpty());
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
