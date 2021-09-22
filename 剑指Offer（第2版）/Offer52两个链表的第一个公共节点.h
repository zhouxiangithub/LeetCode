#pragma once
using namespace std;
#include <unordered_set>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution
{
public:
	//��ϣ����
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		unordered_set<ListNode*> nodes;
		ListNode* tmp = headA;
		while (tmp != nullptr)
		{
			nodes.insert(tmp);
			tmp = tmp->next;
		}
		tmp = headB;
		while (tmp != nullptr)
		{
			if (nodes.count(tmp)) //������ǽڵ���Ϣ������ڵ�ֵ�޹�
			{
				return tmp;
			}
			tmp = tmp->next;
		}
		return nullptr;
	}

	//˫ָ��
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}
		ListNode* pA = headA, * pB = headB;
		while (pA != pB)
		{
			pA = pA == nullptr ? headB : pA->next;
			pB = pB == nullptr ? headA : pB->next;
		}
		return pA;
	}
};