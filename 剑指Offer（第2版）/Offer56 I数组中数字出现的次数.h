#pragma once
using namespace std;
#include <vector>

/*
	Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
	����һ���򵥵����⣺�������һ�������⣬�������ֶ����������Σ���ô����ҵ�������һ�ε����֣���ȫԱ�������������ɣ���
	������ 4��   1��   4��    6
	     0100  0001  0100  0110
		 ���е������Ľ��Ϊ��0111��Ҳ��1��6���Ľ��
		 ����ԭ�򣺵������е����ĵ�һ��������λ��1�ľͷ��ڵ�һ�飬�����е����ĵ�һ��������λ��0�ľͷ��ڵڶ���
		 ��ˣ�1.����ֻ����һ�ε������ڲ�ͬ�����У�2.��ͬ�����ֻᱻ�ֵ���ͬ������
*/
class Solution
{
public:
	vector<int> singleNumbers(vector<int>& nums)
	{
		int ret = 0;
		for (int n : nums)
		{
			ret ^= n;
		}
		int div = 1;
		while ((div & ret) == 0)
		{
			div <<= 1; //�ҵ���һ����Ϊ0��λ
		}
		int a = 0, b = 0;
		for (int n : nums)
		{
			if (div & n)
			{
				a ^= n;
			}
			else
			{
				b ^= n;
			}
		}
		return vector<int>{a, b};
	}
};