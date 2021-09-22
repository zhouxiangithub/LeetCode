#pragma once
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
	string findLongestWord(string s, vector<string>& dictionary)
	{
		string res = "";
		for (string t : dictionary) //t是否是s的子序列
		{
			int i = 0, j = 0;
			while (i < t.length() && j < s.length())
			{
				if (t[i] == s[j])
				{
					i++;
				}
				j++;
			}
			if (i == t.length())
			{
				if (t.length() > res.length() || (t.length() == res.length() && strcmp(t.c_str(), res.c_str()) < 0))
				{
					res = t;
				}
			}
		}
		return res;
	}
};