#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	int index = 0;

	//是否包含无符号数
	bool scanUnsignedInteger(string s)
	{
		int before = index;
		while (s[index] >= '0' && s[index] <= '9')
		{
			index++;
		}
		return index > before;
	}

	//是否包含有符号数
	bool scanInteger(string s)
	{
		if (s[index] == '+' || s[index] == '-')
		{
			index++;
		}
		return scanUnsignedInteger(s);
	}

	bool isNumber(string s)
	{
		if (s.size() == 0) //空字符串
		{
			return false;
		}
		s = s + '|'; //添加结束标志
		while (s[index] == ' ')
		{
			index++;
		}
		bool flag = scanInteger(s); //是否包含整数部分
		if (s[index] == '.')
		{
			index++;
			flag = scanUnsignedInteger(s) || flag;
		}
		if (s[index] == 'E' || s[index] == 'e')
		{
			index++;
			flag = scanInteger(s) && flag;
		}
		while (s[index] == ' ')
		{
			index++;
		}
		return flag && s[index] == '|';
	}
};