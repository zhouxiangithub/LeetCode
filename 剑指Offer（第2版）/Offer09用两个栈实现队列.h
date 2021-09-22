#pragma once
using namespace std;
#include <stack>

class CQueue
{
	//维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作
	stack<int> stack1, stack2;
public:
	CQueue()
	{
		while (!stack1.empty())
		{
			stack1.pop();
		}
		while (!stack2.empty())
		{
			stack2.pop();
		}
	}

	void appendTail(int value)
	{
		stack1.push(value);
	}

	int deleteHead()
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty())
		{
			return -1;
		}
		else
		{
			int deleteItem = stack2.top();
			stack2.pop();
			return deleteItem;
		}
	}
};