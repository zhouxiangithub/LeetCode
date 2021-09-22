#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution
{
public:
	//ʹ�ù�ϣ��洢Ƶ��
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

	//ʹ�ù�ϣ��洢����������ʾһ���ַ���ֵ��ʾ�����״γ��ֵ�������������ַ�ֻ����һ�Σ�����-1��������ַ����ֶ�Σ�
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