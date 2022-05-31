#pragma once
using namespace std;
#include <math.h>

/*
    由于两个n位整数的乘机至多是个2n位数，我们可以从10^n-1开始枚举回文数的左半部分
*/
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
        {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; left--) //枚举回文数的左半部分
        {
            long p = left;
            for (int i = left; i > 0; i /= 10)
            {
                p = p * 10 + i % 10; //翻转左半部分到其自身末尾，构造回文数p
            }
            for (long j = upper; j * j >= p; j--)
            {
                if (p % j == 0)
                {
                    return p % 1337;
                }
            }
        }
    }
};