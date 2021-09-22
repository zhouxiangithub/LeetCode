#pragma once
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* getKthFromEnd(ListNode* head, int k)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* former = head, * latter = head;
		for (int i = 0; i < k; i++)
		{
			former = former->next;
		}
		while (former != nullptr)
		{
			former = former->next;
			latter = latter->next;
		}
		return latter;
	}
};
