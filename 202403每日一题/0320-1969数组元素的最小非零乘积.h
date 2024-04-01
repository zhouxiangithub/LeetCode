#pragma once
using namespace std;

/*
* 缩小最小的, 增加最大的
* [1,2,3,..., 2^p - 2, 2^p - 1]
* [0,0,0,..., 2^p - 1, ... , 2^p - 1]
* [1,1,...,1, 2^p - 2, ... , 2^p - 2, 2^p - 1]
* 2^(p-1) - 1 个, 2^(p-1) - 1 个, 1 个
*/

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    long long power(long long m, long long n) //m^n
    {
        long long res = 1;
        for (; n != 0; n >>= 1)
        {
            if (n & 1)
            {
                res = res * m % mod;
            }
            m = m * m % mod;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        if (p == 1)
        {
            return 1;
        }
        long long x = power(2, p) - 1; //2^p - 1
        long long y = (long long)1 << (p - 1); //2^(p-1)
        return power(x - 1, y - 1) * x % mod; //(2^p - 2)^[2^(p-1) - 1] * (2^p - 1)
    }
};