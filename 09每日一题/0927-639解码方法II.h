#pragma once
using namespace std;
#include <string>

class Solution
{
private:
	static constexpr int mod = 1000000007;
public:
	int numDecodings(string s)
	{
		auto checkOneDigit = [](char ch)->int {
			if (ch == '0')
			{
				return 0;
			}
			return ch == '*' ? 9 : 1;
		};

		auto checkTwoDigits = [](char c0, char c1)->int {
			if (c0 == '*' && c1 == '*') //1:1~9, 2:1~6
			{
				return 15;
			}
			if (c0 == '*')
			{
				return c1 <= '6' ? 2 : 1;
			}
			if (c1 == '*')
			{
				if (c0 == '1')
				{
					return 9;
				}
				if (c0 == '2')
				{
					return 6;
				}
				return 0;
			}
			return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;
		};

		int n = s.size();
		int a = 0, b = 1, c = 0; //a=f[i-2], b=f[i-1], c=f[i]
		for (int i = 1; i <= n; i++)
		{
			c = (long long)b * checkOneDigit(s[i - 1]) % mod;
			if (i > 1)
			{
				c = (c + (long long)a * checkTwoDigits(s[i - 2], s[i - 1])) % mod;
			}
			a = b;
			b = c;
		}
		return c;
	}
};