#pragma once
using namespace std;

/*
    很容易想到 n! 的结果中尾随零的数量，即求：2和5出现的次数的最小值
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