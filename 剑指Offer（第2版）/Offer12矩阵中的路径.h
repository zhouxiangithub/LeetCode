#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int index)
	{
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[index])
		{
			return false;
		}
		if (index == word.size() - 1)
		{
			return true;
		}
		board[i][j] = '\0';
		bool res = dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1)
			|| dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1);
		board[i][j] = word[index];
		return res;
	}

	bool exist(vector<vector<char>>& board, string word)
	{
		int rows = board.size(), columns = board[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (dfs(board, word, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
};