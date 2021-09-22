#pragma once
using namespace std;
#include <vector>

/*
	������
		rows[i][index] columns[j][index] subboxes[i/3][j/3][index]
		�ֱ��ʾ�����ĵ� i �е� j �еĵ�Ԫ�����ڵ��С��к�С�Ź����У����� index+1 ���ֵĴ���
*/
class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		int rows[9][9];
		int columns[9][9];
		int subboxes[9][9][9];

		memset(rows, 0, sizeof(rows));
		memset(columns, 0, sizeof(columns));
		memset(subboxes, 0, sizeof(subboxes));

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char c = board[i][j];
				if (c != '.')
				{
					int index = c - '0' - 1;
					rows[i][index]++;
					columns[j][index]++;
					subboxes[i / 3][j / 3][index]++;;
					if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1)
					{
						return false;
					}
				}
			}
		}

		return true;
	}
};