#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return vector<int>{};
		}
		int rows = matrix.size(), columns = matrix[0].size();
		int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
		vector<int> order(rows * columns);
		int index = 0;
		while (left <= right && top <= bottom)
		{
			for (int c = left; c <= right; c++)
			{
				order[index++] = matrix[top][c];
			}
			for (int r = top + 1; r <= bottom; r++)
			{
				order[index++] = matrix[r][right];
			}
			if (left < right && top < bottom)
			{
				for (int c = right - 1; c > left; c--)
				{
					order[index++] = matrix[bottom][c];
				}
				for (int r = bottom; r > top; r--)
				{
					order[index++] = matrix[r][left];
				}
			}
			left++;
			right--;
			top++;
			bottom--;
		}
		return order;
	}
};