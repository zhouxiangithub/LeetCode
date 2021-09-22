#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution
{
public:
	//使用哈希表存储频数
	char firstUniqChar(string s)
	{
		unordered_map<int, int> count;
		for (char ch : s)
		{
			count[ch]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i]] == 1)
			{
				return s[i];
			}
		}
		return ' ';
	}

	//使用哈希表存储索引：键表示一个字符，值表示它的首次出现的索引（如果该字符只出现一次）或者-1（如果该字符出现多次）
	char firstUniqChar(string s)
	{
		unordered_map<int, int> position;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (position.count(s[i]))
			{
				position[s[i]] = -1;
			}
			else
			{
				position[s[i]] = i;
			}
		}
		int first = n;
		for (unordered_map<int, int>::iterator it = position.begin(); it != position.end(); it++)
		{
			if (it->second != -1 && it->second < first)
			{
				first = it->second;
			}
		}
		return first == n ? ' ' : s[first];
	}
};