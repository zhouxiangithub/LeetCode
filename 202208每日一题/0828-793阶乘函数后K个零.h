#pragma once
using namespace std;

class Solution {
public:
    //x!中5的个数
    int zeta(long x)
    {
        int res = 0;
        while (x)
        {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    long long help(int k)
    {
        long long l = 0;
        long long r = 5LL * k;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (zeta(mid) < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r + 1;
    }

    //(k+1)!末尾0的个数不小于(k+1)的最小数 - k!末尾0的个数不小于k的最小数
    int preimageSizeFZF(int k) {
        return help(k + 1) - help(k);
    }
};