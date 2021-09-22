#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution
{
public:
	//1.����
	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		vector<int> vec(k, 0);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; i++)
		{
			vec[i] = arr[i];
		}
		return vec;
	}

	//2.��
	vector<int> getLeastNumbers2(vector<int>& arr, int k)
	{
		vector<int> vec(k, 0);
		if (k == 0)
		{
			return vec;
		}
		priority_queue<int> q; //C++�еĶѣ����ȶ��У�Ϊ�����
		for (int i = 0; i < k; i++)
		{
			q.push(arr[i]);
		}
		for (int i = k; i < arr.size(); i++)
		{
			if (q.top() > arr[i])
			{
				q.pop();
				q.push(arr[i]);
			}
		}
		for (int i = 0; i < k; i++)
		{
			vec[i] = q.top();
			q.pop();
		}
		return vec;
	}
};