#pragma once
using namespace std;
#include <vector>
#include <stack>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution
{
public:
	vector<int> reversePrint(ListNode* head)
	{
		vector<int> ans;
		stack<int> st;
		while (head)
		{
			st.push(head->val);
			head = head->next;
		}
		while (!st.empty())
		{
			ans.emplace_back(st.top());
			st.pop();
		}
		return ans;
	}
};