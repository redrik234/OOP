#include "stdafx.h"
#include "../StringStack/StringStack.h"
#include <iostream>

using namespace std;

struct EmptyStack
{
	CStringStack stringStack;
};

BOOST_FIXTURE_TEST_SUITE(Stack, EmptyStack)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty_by_default)
		{
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_not_get_top_element_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(stringStack.GetTopElement(), std::logic_error);
		}

		BOOST_AUTO_TEST_CASE(can_not_pop_elements_when_stack_is_empty)
		{
			BOOST_CHECK_THROW(stringStack.Pop(), std::logic_error);
		}

		BOOST_AUTO_TEST_CASE(can_push_elements)
		{
			stringStack.Push("42");
			BOOST_CHECK(!stringStack.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_there_are_elements)

		BOOST_AUTO_TEST_CASE(can_pop_elements)
		{
			stringStack.Push("42343545");
			stringStack.Pop();
			BOOST_CHECK(stringStack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(can_get_top_element)
		{
			stringStack.Push("HelloWorld");
			BOOST_CHECK_EQUAL(stringStack.GetTopElement(), "HelloWorld");
		}

		BOOST_AUTO_TEST_CASE(can_get_size_of_stack)
		{
			stringStack.Push("World");
			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(1));
		}

		BOOST_AUTO_TEST_CASE(can_delete_all_elements_in_stack)
		{
			stringStack.Push("a");
			stringStack.Push("b");
			stringStack.Push("c");

			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(3));

			stringStack.Clear();
			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(0));
		}

		BOOST_AUTO_TEST_CASE(can_not_pop_element_when_stack_has_been_cleared)
		{
			stringStack.Push("a");
			stringStack.Push("b");
			stringStack.Push("c");

			BOOST_CHECK_EQUAL(stringStack.GetSize(), size_t(3));

			stringStack.Clear();

			BOOST_CHECK_THROW(stringStack.Pop(), std::logic_error);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()