#pragma once
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
	{
		stack<int> stack;
		int i = 0;
		for (int x : pushed)
		{
			stack.push(x);
			while (!stack.empty() && stack.top() == popped[i])
			{
				stack.pop();
				i++;
			}
		}
		return stack.empty();
	}
};
