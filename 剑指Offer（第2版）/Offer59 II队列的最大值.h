#pragma once
using namespace std;
#include <queue>
#include <deque>

class MaxQueue
{
public:
	queue<int> q;
	deque<int> q_m;

	MaxQueue() {}

	int max_value()
	{
		if (q_m.empty())
		{
			return -1;
		}
		return q_m.front();
	}

	void push_back(int value)
	{
		q.push(value);
		while (!q_m.empty() && q_m.back() < value)
		{
			q_m.pop_back();
		}
		q_m.push_back(value);
	}

	int pop_front()
	{
		if (q.empty())
		{
			return -1;
		}
		int ans = q.front();
		if (ans == q_m.front())
		{
			q_m.pop_front();
		}
		q.pop();
		return ans;
	}
};