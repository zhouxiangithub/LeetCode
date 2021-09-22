#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int index = s.size() - 1;
		while (s[index] == ' ')
		{
			index--;
		}
		int len = 0;
		while (index >= 0 && s[index] != ' ')
		{
			len++;
			index--;
		}
		return len;
	}
};