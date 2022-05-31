#pragma once
using namespace std;

/*
    求第几小等价于求有多少数字不超过x
    对于乘法表的第i行，不超过x的数字有min(x/i,n)个
    所以整个乘法表不超过x的数字个数为：累加和min(x/i,n), i=1,...,m
    i=1,2,...,x/n, x/n+1,...,m
*/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right)
        {
            int x = left + (right - left) / 2;
            int count = (x / n) * n;
            for (int i = x / n + 1; i <= m; i++)
            {
                count += x / i;
            }
            if (count >= k) //不能在count=k时直接返回结果，而应继续二分，最终返回能满足count=k的最小x值
            {
                right = x;
            }
            else
            {
                left = x + 1;
            }
        }
        return left;
    }
};