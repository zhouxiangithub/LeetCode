#pragma once
using namespace std;
#include <string>
#include <map>

/*
	������
		dp[i]�������ַ�s[i]Ϊ��β�ġ�����ظ����ַ������ĳ���
		�̶��ұ߽�i�����ַ�s[i]��߾����������ͬ�ַ�Ϊs[j]������s[i]=s[j]
		1.��j<0ʱ��˵��s[i]�������ͬ�ַ���dp[i]=dp[i-1]+1
		2.��dp[i-1]<i-jʱ��˵���ַ�s[j]�����ַ���dp[i-1]����֮�⣬dp[i]=dp[i-1]+1
		3.��dp[i-1]>=i-j��˵���ַ�s[j]�����ַ���dp[i-1]����֮�ڣ�dp[i]=i-j
*/
class Solution
{
public:
	//��̬�滮+���Ա���
	int lengthOfLongestSubstring(string s)
	{
		int res = 0, tmp = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i - 1;
			while (j >= 0 && s[i] != s[j])
			{
				j--;
			}
			tmp = tmp < i - j ? tmp + 1 : i - j;
			res = max(res, tmp);
		}
		return res;
	}

	//˫ָ��+��ϣ��
	int lengthOfLongestSubstring(string s)
	{
		map<char, int> dic;
		int i = -1, res = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (dic.count(s[j]))
			{
				i = max(i, dic[s[j]]);
			}
			dic[s[j]] = j;
			res = max(res, j - i);
		}
		return res;
	}
};