#pragma once

class CStringStack
{
	class Node
	{
	public:
		Node(const  std::string &value, const  std::shared_ptr<Node> &next = nullptr)
			: value(value)
			, next(next)
		{
		}

		std::string value;
		std::shared_ptr<Node> next;
	};
public:
	CStringStack();

	void Push(const  std::string &string);
	void Pop();
	std::string GetTopElement() const;
	size_t GetSize() const;
	bool IsEmpty() const;
	void Clear();

	~CStringStack();
private:
	std::shared_ptr<Node> m_top;
	size_t m_size;
};