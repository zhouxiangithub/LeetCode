#pragma once
using namespace std;

class Solution
{
public:
	int add(int a, int b)
	{
		while (b != 0)
		{
			int c = (unsigned int)(a & b) << 1; //��λ
			a ^= b; //�ǽ�λ��
			b = c; //��λ
		}
		return a;
	}
};