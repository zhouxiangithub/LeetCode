#pragma once
using namespace std;
#include <vector>

class Solution
{
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int rows = matrix.size(), columns = matrix[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (matrix[i][j] == target)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int rows = matrix.size(), columns = matrix[0].size();
		int row = 0, column = columns - 1;
		while (row < rows && column >= 0)
		{
			int num = matrix[row][column];
			if (num == target)
			{
				return true;
			}
			else if (num < target)
			{
				row++;
			}
			else
			{
				column--;
			}
		}
		return false;
	}

	//¶þ·ÖËÑË÷
	bool binarySearch(vector<vector<int>> matrix, int target, int start, bool flag)
	{
		int low = start;
		int high = flag ? matrix[0].size() - 1 : matrix.size() - 1;
		while (low <= high)
		{
			int mid = (high - low) / 2 + low;
			if (flag)
			{
				if (matrix[start][mid] < target)
				{
					low = mid + 1;
				}
				else if (matrix[start][mid] > target)
				{
					high = mid - 1;
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (matrix[mid][start] < target)
				{
					low = mid + 1;
				}
				else if (matrix[mid][start] > target)
				{
					high = mid - 1;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int min_ = min(matrix.size(), matrix[0].size());
		for (int i = 0; i < min_; i++)
		{
			bool ver = binarySearch(matrix, target, i, true);
			bool hor = binarySearch(matrix, target, i, false);
			if (ver || hor)
			{
				return true;
			}
		}
		return false;
	}
};