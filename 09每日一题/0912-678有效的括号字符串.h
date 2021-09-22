#pragma once
using namespace std;
#include <string>
#include <stack>

class Solution
{
public:
	bool checkValidString(string s)
	{
		stack<int> leftStack;
		stack<int> startStack;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			char c = s[i];
			if (c == '(')
			{
				leftStack.push(i);
			}
			else if (c == '*')
			{
				startStack.push(i);
			}
			else
			{
				if (!leftStack.empty())
				{
					leftStack.pop();
				}
				else if (!startStack.empty())
				{
					startStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
		while (!leftStack.empty() && !startStack.empty())
		{
			int leftIndex = leftStack.top();
			int startIndex = startStack.top();
			leftStack.pop();
			startStack.pop();
			if (leftIndex > startIndex)
			{
				return false;
			}
		}
		return leftStack.empty();
	}
};