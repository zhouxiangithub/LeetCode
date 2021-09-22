#pragma once
using namespace std;
#include <string>
#include <map>

/*
	分析：
		dp[i]代表以字符s[i]为结尾的“最长不重复子字符串”的长度
		固定右边界i，设字符s[i]左边距离最近的相同字符为s[j]，即：s[i]=s[j]
		1.当j<0时，说明s[i]左边无相同字符，dp[i]=dp[i-1]+1
		2.当dp[i-1]<i-j时，说明字符s[j]在子字符串dp[i-1]区间之外，dp[i]=dp[i-1]+1
		3.当dp[i-1]>=i-j，说明字符s[j]在子字符串dp[i-1]区间之内，dp[i]=i-j
*/
class Solution
{
public:
	//动态规划+线性遍历
	int lengthOfLongestSubstring(string s)
	{
		int res = 0, tmp = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i - 1;
			while (j >= 0 && s[i] != s[j])
			{
				j--;
			}
			tmp = tmp < i - j ? tmp + 1 : i - j;
			res = max(res, tmp);
		}
		return res;
	}

	//双指针+哈希表
	int lengthOfLongestSubstring(string s)
	{
		map<char, int> dic;
		int i = -1, res = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (dic.count(s[j]))
			{
				i = max(i, dic[s[j]]);
			}
			dic[s[j]] = j;
			res = max(res, j - i);
		}
		return res;
	}
};