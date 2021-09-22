#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	string reverseWords(string s)
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		string ans;
		int j = s.size() - 1, i = j;
		while (i >= 0)
		{
			while (i >= 0 && s[i] != ' ')
			{
				i--;
			}
			for (int k = i + 1; k <= j; k++)
			{
				ans += s[k];
			}
			ans += " ";
			while (i >= 0 && s[i] == ' ')
			{
				i--;
			}
			j = i;
		}
		return ans.erase(ans.find_last_not_of(" ") + 1);
	}
};