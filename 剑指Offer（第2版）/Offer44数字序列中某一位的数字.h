#pragma once
using namespace std;
#include <string>

/*
	事实上，我们可以找到如下规律：
	数字x在该数字序列中对应的位置为：
	当 0<=x<=9 时，为：x
	当 x>10 时，为：{nx-[10^(n-1)+10^(n-2)+...+10^1], ..., nx-[10^(n-1)+10^(n-2)+...+10^1]+(n-1)}，其中n代表数字x的位数
	然而，本题可以认为是：已知该数字序列中的位置，求数字x
*/
/* 数字范围    数量  位数    占多少位
	1-9        9      1       9
	10-99      90     2       180
	100-999    900    3       2700
	1000-9999  9000   4       36000  ...

	例如 2901 = 9 + 180 + 2700 + 12 即一定是4位数，第12位 n = 12;
	数据为 = 1000 + (12 - 1)/ 4  = 1000 + 2 = 1002
	定位1002中的位置 = (n - 1) %  4 = 3    s.charAt(3) = 2;
*/
class Solution
{
public:
	int findNthDigit(int n)
	{
		int digit = 1; //n所在数字的位数
		long start = 1; //数字范围开始的第一个数
		long count = 9; //占多少位
		while (n > count)
		{
			n -= count;
			digit++;
			start *= 10;
			count = digit * start * 9;
		}
		long num = start + (n - 1) / digit;
		return to_string(num)[(n - 1) % digit] - '0';
	}
};