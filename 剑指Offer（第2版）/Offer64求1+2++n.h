#pragma once
using namespace std;

/*
	������
		���� A && B����� A=False���򲻻�ȥִ�� B
		���� A || B����� A=True���򲻻�ȥִ�� B
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