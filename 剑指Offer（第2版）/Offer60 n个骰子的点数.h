#pragma once
using namespace std;
#include <vector>

/*
	������
	�����������ӵĵ���ֻ����Ϊ1��6����˸��� f(n-1,x) 
	���� f(n,x+1), f(n,x+2), ... , f(n,x+6)��ء�
	���������f(n-1)�и������͵ĸ��ʣ������������f(n)����������
	�������f(n-1)��f(n)�ĵ��ơ�

*/
class Solution
{
public:
	vector<double> dicesProbability(int n)
	{
		vector<double> dp(6, 1.0 / 6.0);
		for (int i = 2; i <= n; i++)
		{
			//i�����ӵ�ֵ��ΧΪ��[i, 6*i]������6*i-i+1=5*i+1��ֵ
			vector<double> tmp(5 * i + 1, 0);
			for (int j = 0; j < dp.size(); j++)
			{
				for (int k = 0; k < 6; k++)
				{
					tmp[j + k] += dp[j] / 6.0;
				}
			}
			dp = tmp;
		}
		return dp;
	}
};