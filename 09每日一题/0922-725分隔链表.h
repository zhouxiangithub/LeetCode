#pragma once
using namespace std;
#include <vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution
{
public:
	vector<ListNode*> splitListToParts(ListNode* head, int k)
	{
		int len = 0;
		ListNode* temp = head;
		while (temp != nullptr)
		{
			len++;
			temp = temp->next;
		}
		int quotient = len / k, remainder = len % k;

		vector<ListNode*> parts(k, nullptr);
		ListNode* curr = head;
		for (int i = 0; i < len && curr != nullptr; i++)
		{
			parts[i] = curr;
			int partSize = quotient + (i < remainder ? 1 : 0);
			for (int j = 1; j < partSize; j++)
			{
				curr = curr->next;
			}
			ListNode* next = curr->next;
			curr->next = nullptr;
			curr = next;
		}
		return parts;
	}
};