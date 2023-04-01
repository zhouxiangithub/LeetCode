#pragma once
using namespace std;
#include <string>
#include <numeric>

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string res = s;
        s = s + s; //将s延长一倍以方便截取轮转后的字符串t
        int g = gcd(b, n);
        for (int i = 0; i < n; i += g) //枚举做轮转的次数
        {
            for (int j = 0; j < 10; j++) //枚举对t的奇数位做累加操作的次数
            {
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) //枚举对t的偶数位做累加操作的次数
                {
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2)
                    {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2)
                    {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
            }
        }
        return res;
    }
};