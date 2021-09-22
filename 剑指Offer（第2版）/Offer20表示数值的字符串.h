#pragma once
using namespace std;
#include <string>

class Solution
{
public:
	int index = 0;

	//�Ƿ�����޷�����
	bool scanUnsignedInteger(string s)
	{
		int before = index;
		while (s[index] >= '0' && s[index] <= '9')
		{
			index++;
		}
		return index > before;
	}

	//�Ƿ�����з�����
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
		if (s.size() == 0) //���ַ���
		{
			return false;
		}
		s = s + '|'; //��ӽ�����־
		while (s[index] == ' ')
		{
			index++;
		}
		bool flag = scanInteger(s); //�Ƿ������������
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