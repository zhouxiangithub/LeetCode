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
		//��תÿ���±��2k�ı�����ʼ�ģ�����Ϊk���Ӵ��������Ӵ��ĳ��Ȳ���k����ת�����Ӵ���
		for (int i = 0; i < n; i += 2 * k)
		{
			reverse(s.begin() + i, s.begin() + min(i + k, n));
		}
		return s;
	}
};
