#pragma once
#include <iostream>
using namespace std;

/*2021-08-20*/
class Solution
{
public:
	string reverseStr(string s, int k)
	{
		int n = s.length();
		//反转每个下标从2k的倍数开始的，长度为k的子串。若该子串的长度不足k，则反转整个子串。
		for (int i = 0; i < n; i += 2 * k)
		{
			reverse(s.begin() + i, s.begin() + min(i + k, n));
		}
		return s;
	}
};
