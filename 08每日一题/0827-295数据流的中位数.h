#pragma once
using namespace std;
#include <queue>

/*2021-08-27*/
class MedianFinder
{
	priority_queue<int, vector<int>, less<int>> qMin; //��¼С�ڵ�����λ������
	priority_queue<int, vector<int>, greater<int>> qMax; //��¼������λ������

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