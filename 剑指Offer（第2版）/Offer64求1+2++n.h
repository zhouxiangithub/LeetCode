#pragma once
using namespace std;

/*
	分析：
		对于 A && B，如果 A=False，则不会去执行 B
		对于 A || B，如果 A=True，则不会去执行 B
*/
class Solution
{
public:
	int sumNums(int n)
	{
		n && (n += sumNums(n - 1));
		return n;
	}
};