#pragma once
using namespace std;

/*
	分析： (randX() - 1)*Y + randY() 可以等概率的生成 [1, X * Y] 范围的随机数
*/
class Solution
{
public:
	int rand7(); //1~7

	int rand10()
	{
		while (true)
		{
			int num = (rand7() - 1) * 7 + rand7(); //1~49
			if (num <= 40)
			{
				return 1 + num % 10;
			}
			num = (num - 40 - 1) * 7 + rand7(); //1~63
			if (num <= 60)
			{
				return 1 + num % 10;
			}
			num = (num - 60 - 1) * 7 + rand7(); //1~21
			if (num <= 20)
			{
				return 1 + num % 10;
			}
		}
	}
};