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
			//如果玩家可以在阻碍者之前达到目的地，不可能出现阻碍者在玩家前往目的地的中途拦截！！
			if (ghostDistance <= distance)
			{
				return false;
			}
		}
		return true;
	}
};
