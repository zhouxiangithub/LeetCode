#pragma once
using namespace std;
#include <numeric>

class Solution {
public:
    int commonFactors(int a, int b) {
        int c = gcd(a, b), ans = 0;
        for (int i = 1; i * i <= c; i++)
        {
            if (c % i == 0)
            {
                ans++;
                if (i * i != c)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};