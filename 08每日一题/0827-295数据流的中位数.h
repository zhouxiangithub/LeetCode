#pragma once
using namespace std;
#include <queue>

/*2021-08-27*/
class MedianFinder
{
	priority_queue<int, vector<int>, less<int>> qMin; //记录小于等于中位数的数
	priority_queue<int, vector<int>, greater<int>> qMax; //记录大于中位数的数

	MedianFinder()
	{
		
	}

	void addNum(int num)
	{
		if (qMin.empty() || num <= qMin.top())
		{
			qMin.push(num);
			if (qMin.size() > qMax.size() + 1)
			{
				qMax.push(qMin.top());
				qMin.pop();
			}
		}
		else
		{
			qMax.push(num);
			if (qMax.size() > qMin.size())
			{
				qMin.push(qMax.top());
				qMax.pop();
			}
		}
	}

	double findMedian()
	{
		if (qMin.size() > qMax.size())
		{
			return qMin.top();
		}
		return (qMin.top() + qMax.top()) / 2.0;
	}
};