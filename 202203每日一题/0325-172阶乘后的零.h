#pragma once
using namespace std;

/*
    �������뵽 n! �Ľ����β���������������2��5���ֵĴ�������Сֵ
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = 5; i <= n; i += 5)
        {
            for (int j = i; j % 5 == 0; j /= 5)
            {
                res++;
            }
        }
        return res;
    }
};