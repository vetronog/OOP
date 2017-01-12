#pragma once

class CStringStack
{
	struct Node
	{
		Node(const std::string &value, const std::shared_ptr<Node> &next = nullptr);

		std::string value;
		std::shared_ptr<Node> next;
	};
public:
	CStringStack();
	CStringStack(const CStringStack &other);
	CStringStack(CStringStack &&other);

	void Push(const std::string &string);
	void Pop();
	std::string GetString() const;
	size_t GetStackSize() const;
	bool IsStackEmpty() const;
	void Clear();

	CStringStack& operator=(const CStringStack &assigns_stack);
	CStringStack& operator=(CStringStack &&copied_stack);

	~CStringStack();
private:
	std::shared_ptr<Node> s_top;
	size_t s_size;
};
