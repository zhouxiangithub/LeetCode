#pragma once
using namespace std;
#include <vector>

/*
	������
		�����֪[l,r]������͵���target����ôö����һ������ʱ������[l+1,r]�ĺͱ�ȻС��target��
		���ǾͲ���Ҫ�ٴ�l+1�ٿ�ʼ�ظ�ö���ˣ����Ǵ�r+1��ʼö�١�
*/
class Solution
{
public:
	vector<vector<int>> findContinuousSequence(int target)
	{
		vector<vector<int>> ans;
		vector<int> tmp;
		for (int l = 1, r = 2; l < r;)
		{
			int sum = (l + r) * (r - l + 1) / 2;
			if (sum == target)
			{
				tmp.clear();
				for (int i = l; i <= r; i++)
				{
					tmp.emplace_back(i);
				}
				ans.emplace_back(tmp);
				l++;
			}
			else if (sum < target)
			{
				r++;
			}
			else
			{
				l++;
			}
		}
		return ans;
	}
};