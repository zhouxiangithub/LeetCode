#pragma once
using namespace std;
#include <vector>

/*
	要求：时间复杂度是O(n)，空间复杂度是O(1)
	考虑一个简单的问题：如果除了一个数字外，其它数字都出现了两次，那么如何找到出现了一次的数字？（全员进行异或操作即可！）
	分析： 4，   1，   4，    6
	     0100  0001  0100  0110
		 所有的数异或的结果为：0111，也即1和6异或的结果
		 划分原则：当数组中的数的第一个二进制位是1的就分在第一组，数组中的数的第一个二进制位是0的就分在第二组
		 如此：1.两个只出现一次的数字在不同的组中；2.相同的数字会被分到相同的组中
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
			div <<= 1; //找到第一个不为0的位
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