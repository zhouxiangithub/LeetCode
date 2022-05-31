#pragma once
using namespace std;

/*
    排列组合：
        当 n=2 时，0<=x<100，x的选择可以由两部分构成：只有一位数的x和有两位数的x。
        只有一位数的x：0~9，共10种；
        有两位数的x可以由组合数学进行计算：
            第一位的选择有 9 种，即 1~9；第二位的选择也有 9 种，即 0~9 中除去第一位的选择。共：9*9=9*A(9,1)种。
        所以当 n=2 时，总共有：10+9*A(9,1) 种。
        同理，可以推导出，当 n=3 时，总共有：10+9*A(9,1)+9*A(9,2) 种。 
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 10;
        }
        int ans = 10, cur = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cur *= (9 - i);
            ans += 9 * cur;
        }
        return ans;
    }
};