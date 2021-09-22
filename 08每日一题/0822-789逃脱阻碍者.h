#pragma once
using namespace std;
#include <vector>

/*2021-08-22*/
class Solution
{
public:
	int manhattanDistance(vector<int>& point1, vector<int>& point2)
	{
		return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
	}

	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target)
	{
		vector<int> source(2);
		int distance = manhattanDistance(source, target);
		for (auto& ghost : ghosts)
		{
			int ghostDistance = manhattanDistance(ghost, target);
			//�����ҿ������谭��֮ǰ�ﵽĿ�ĵأ������ܳ����谭�������ǰ��Ŀ�ĵص���;���أ���
			if (ghostDistance <= distance)
			{
				return false;
			}
		}
		return true;
	}
};
