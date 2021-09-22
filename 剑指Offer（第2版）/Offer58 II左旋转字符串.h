#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	string reverseLeftWords(string s, int n)
	{
		string res;
		for (int i = n; i < s.size(); i++)
		{
			res += s[i];
		}
		for (int j = 0; j < n; j++)
		{
			res += s[j];
		}
		return res;
	}
};