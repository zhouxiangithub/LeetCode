#pragma once
using namespace std;
#include <unordered_map>

class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val)
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution
{
public:
	unordered_map<Node*, Node*> cacheNode;

	Node* copyRandomList(Node* head)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		if (!cacheNode.count(head))
		{
			Node* headNew = new Node(head->val);
			cacheNode[head] = headNew;
			headNew->next = copyRandomList(head->next);
			headNew->random = copyRandomList(head->random);
		}
		return cacheNode[head];
	}
};