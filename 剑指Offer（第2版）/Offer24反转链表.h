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
	ListNode* reverseList(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr)
		{
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	ListNode* reverseList1(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* newHead = reverseList1(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}
};