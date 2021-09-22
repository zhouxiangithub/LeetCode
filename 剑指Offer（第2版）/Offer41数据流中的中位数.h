#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

//1.≈≈–Ú
class MedianFinder
{
	vector<double> store;
public:
	MedianFinder()
	{

	}

	void addNum(int num)
	{
		store.push_back(num);
	}

	double findMedian()
	{
		sort(store.begin(), store.end());
		int n = store.size();
		return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
	}
};

//2.∂—
class MedianFinder2
{
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
public:
	MedianFinder2()
	{

	}

	void addNum(int num)
	{
		max_heap.push(num);
		min_heap.push(max_heap.top());
		max_heap.pop();
		if (max_heap.size() < min_heap.size())
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}

	double findMedian()
	{
		return max_heap.size() > min_heap.size() ? (double)max_heap.top() : (max_heap.top() + min_heap.top()) * 0.5;
	}
};