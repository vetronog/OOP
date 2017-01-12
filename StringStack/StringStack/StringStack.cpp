#include "stdafx.h"
#include "StringStack.h"

CStringStack::CStringStack()
	: s_top(nullptr)
	, s_size(0)
{
}

CStringStack::CStringStack(const CStringStack &other)
{
	if (std::addressof(other) != this)
	{
		std::shared_ptr<Node> tmp = other.s_top;
		std::shared_ptr<Node> currentElement = std::make_shared<Node>(tmp->value);
		s_top = currentElement;

		tmp = tmp->next;
		while (tmp != nullptr)
		{
			currentElement->next = std::make_shared<Node>(tmp->value);
			currentElement = currentElement->next;

			tmp = tmp->next;
		}
		s_size = other.s_size;
	};
}

CStringStack::CStringStack(CStringStack &&other)
{
	if (std::addressof(other) != this)
	{
		s_top = other.s_top;
		s_size = other.s_size;
		other.s_top = nullptr;
		other.s_size = 0;
	}
}

void CStringStack::Push(const std::string &string)
{
	s_top = std::make_shared<Node>(string, s_top);
	++s_size;
}

void CStringStack::Pop()
{
	if (IsStackEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	s_top = s_top->next;
	s_size--;
}

std::string CStringStack::GetString() const
{
	if (IsStackEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	return s_top->value;
}

size_t CStringStack::GetStackSize() const
{
	return s_size;
}

bool CStringStack::IsStackEmpty() const
{
	return (s_size == 0);
}

void CStringStack::Clear()
{
	while (s_top != nullptr)
	{
		s_top = s_top->next;
		s_size--;
	}
}

CStringStack& CStringStack::operator=(const CStringStack &assigns_stack)
{
	if (std::addressof(assigns_stack) != this)
	{
		std::shared_ptr<Node> tmp = assigns_stack.s_top;
		std::shared_ptr<Node> current_point = std::make_shared<Node>(tmp->value, nullptr);
		s_top = current_point;
		tmp = tmp->next;
		while (tmp != nullptr)
		{
			current_point->next = std::make_shared<Node>(tmp->value, nullptr);
			current_point = current_point->next;
			tmp = tmp->next;
		}
		s_size = assigns_stack.GetStackSize();
	}
	return *this;
};

CStringStack & CStringStack::operator=(CStringStack &&	copied_stack)
{
	if (std::addressof(copied_stack) != this)
	{
		s_top = copied_stack.s_top;
		s_size = copied_stack.s_size;
		copied_stack.s_top = nullptr;
		copied_stack.s_size = 0;
	}
	return *this;
};


CStringStack::~CStringStack()
{
	Clear();
}

CStringStack::Node::Node(const std::string & value, const std::shared_ptr<Node>& next)
	: value(value)
	, next(next)
{
}