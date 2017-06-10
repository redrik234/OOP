#include "stdafx.h"
#include "StringStack.h"

using namespace std;

CStringStack::CStringStack()
	:m_top(nullptr)
	, m_size(0)
{
}

void CStringStack::Push(const  string &string)
{
	m_top = make_shared<Node>(string, m_top);
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw logic_error("Can't pop element from empty stack is empty");
	}
	m_top = m_top->next;
	--m_size;
}

string CStringStack::GetTopElement() const
{
	if (IsEmpty())
	{
		throw logic_error("Can't get element from empty stack");
	}
	return m_top->value;
}


size_t CStringStack::GetSize() const
{
	return m_size;
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}

void CStringStack::Clear()
{
	while (m_top != nullptr)
	{
		--m_size;
		m_top = m_top->next;
	}
}

CStringStack::~CStringStack()
{
	Clear();
}