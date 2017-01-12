#include "stdafx.h"
#include "../StringStack/StringStack.h"

struct StringStack_
{
	CStringStack stack;
};

BOOST_FIXTURE_TEST_SUITE(StringStack, StringStack_)
		
	BOOST_AUTO_TEST_CASE(is_empty_by_default)
		{
			BOOST_CHECK_EQUAL(stack.IsStackEmpty(), true);
			BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
		}

	BOOST_AUTO_TEST_CASE(can_add_element)
	{
		stack.Push("abcdef");
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
		BOOST_CHECK(!stack.IsStackEmpty());
		BOOST_CHECK_EQUAL(stack.GetString(), "abcdef");
	}

	BOOST_AUTO_TEST_CASE(can_return_element)
	{
		stack.Push("abcdef");
		BOOST_CHECK_EQUAL(stack.GetString(), "abcdef");
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
	}

	BOOST_AUTO_TEST_CASE(can_delete_element)
	{
		stack.Push("abcdef");
		stack.Push("abcdeg");
		stack.Push("abcdeh");
		stack.Push("abcdej");
		stack.Push("abcdek");
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 5);
		BOOST_CHECK(!stack.IsStackEmpty());
		BOOST_CHECK_EQUAL(stack.GetString(), "abcdek");
		stack.Pop();
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 4);
		BOOST_CHECK(!stack.IsStackEmpty());
		BOOST_CHECK_EQUAL(stack.GetString(), "abcdej");
	}

	BOOST_AUTO_TEST_CASE(first_stack_is_independent)
	{
		stack.Push("abc");
		stack.Push("qwerty");
		CStringStack stack2(stack);
		stack2.Push("asfsdgag");
		CStringStack stack3(stack);
		stack3.Push("xczbdfbz");
		BOOST_CHECK_EQUAL(stack.GetString(), "qwerty");
	}

	BOOST_AUTO_TEST_CASE(can_be_moved)
	{
		stack.Push("abc");
		stack.Push("qwerty");
		CStringStack stack2 = std::move(stack);
		BOOST_CHECK(stack.IsStackEmpty());
		BOOST_CHECK_EQUAL(stack2.GetString(), "qwerty");
		stack2.Pop();
		BOOST_CHECK_EQUAL(stack2.GetString(), "abc");
	}

	BOOST_AUTO_TEST_CASE(can_be_assigned)
	{
		stack.Push("abc");
		stack.Push("qwerty");
		CStringStack stack2;
		stack2 = stack;
		BOOST_CHECK_EQUAL(stack2.GetString(), stack.GetString());
		stack.Pop();
		stack2.Pop();
		BOOST_CHECK_EQUAL(stack2.GetString(), stack.GetString());
	}

	BOOST_AUTO_TEST_CASE(can_be_assigned_with_move)
	{
		CStringStack stack2;
		stack2 = CStringStack();
		BOOST_CHECK(stack.IsStackEmpty());
	}

	BOOST_AUTO_TEST_CASE(can_be_constructed_from_other_stack)
	{
		stack.Push("abcdef");
		stack.Push("qwerty");
		CStringStack stack2(stack);
		BOOST_CHECK_EQUAL(stack2.GetString(), stack.GetString());
	}

	BOOST_AUTO_TEST_SUITE(throw_exception_if)

		BOOST_AUTO_TEST_CASE(pop_empty_stack)
		{
			BOOST_REQUIRE_THROW(stack.Pop(), std::exception);
		}

		BOOST_AUTO_TEST_CASE(get_element_from_empty_stack)
		{
			BOOST_REQUIRE_THROW(stack.GetString(), std::exception);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()