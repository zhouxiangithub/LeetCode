#pragma once
using namespace std;
#include <functional>

class Node
{
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class Solution
{
public:
	Node* flatten(Node* head)
	{
		function<Node* (Node*)> dfs = [&](Node* node)
		{
			Node* cur = node;
			Node* last = nullptr; //记录链表的最后一个节点

			while (cur)
			{
				Node* next = cur->next;

				if (cur->child) //子节点
				{
					Node* child_last = dfs(cur->child);
					next = cur->next;

					cur->next = cur->child;
					cur->child->prev = cur;

					if (next)
					{
						child_last->next = next;
						next->prev = child_last;
					}

					cur->child = nullptr;
					last = child_last;
				}
				else
				{
					last = cur;
				}
				cur = next;
			}
			return last;
		};

		dfs(head);
		return head;
	}
};