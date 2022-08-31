#pragma once
using namespace std;

class Solution {
public:
    //x!��5�ĸ���
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

    //(k+1)!ĩβ0�ĸ�����С��(k+1)����С�� - k!ĩβ0�ĸ�����С��k����С��
    int preimageSizeFZF(int k) {
        return help(k + 1) - help(k);
    }
};