#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution
{
public:
	//dp[i][j]��s ��ǰ i ���ַ��� p ��ǰ j ���ַ��Ƿ���ƥ��
	bool isMatch(string s, string p)
	{
		int n = s.size(), m = p.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
		for (int i = 0; i < n + 1; i++)
		{
			for (int j = 0; j < m + 1; j++)
			{
				if (j == 0)
				{
					dp[i][j] = i == 0;
				}
				else
				{
					if (p[j - 1] != '*')
					{
						if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
						{
							dp[i][j] = dp[i - 1][j - 1];
						}
					}
					else
					{
						if (j >= 2) // '*'ƥ����0��
						{
							dp[i][j] = dp[i][j] || dp[i][j - 2];
						}
						if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
						{
							dp[i][j] = dp[i][j] || dp[i-1][j];
						}
					}
				}
			}
		}
		return dp[n][m];
	}
};