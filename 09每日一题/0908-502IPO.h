#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
	������
		ÿ�ν���ѡ��ʱ��Ӧ�ô�����Ͷ���ʱ�С�ڵ��� w ����Ŀ��ѡ������������Ŀ j
*/
class Solution
{
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
	{
		int n = profits.size();
		vector<pair<int, int>> arr;
		priority_queue<int, vector<int>> pq; //Ĭ�ϴ����
		int index = 0;

		for (int i = 0; i < n; i++)
		{
			arr.emplace_back(make_pair(capital[i], profits[i])); // (�ʱ�,����)
		}
		sort(arr.begin(), arr.end()); //���ʱ���С��������

		for (int i = 0; i < k; i++)
		{
			while (index < n && arr[index].first <= w)
			{
				pq.push(arr[index].second);
				index++;
			}
			if (!pq.empty())
			{
				w += pq.top();
				pq.pop();
			}
			else
			{
				break;
			}
		}

		return w;
	}
};