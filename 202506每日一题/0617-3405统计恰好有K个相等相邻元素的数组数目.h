#pragma once
using namespace std;

/*
    n 个数有 n-1 对相邻的元素，其中 k 对相等，则 n-1-k 对不等
    n-1-k 个隔板的方案数为 C(n-1, n-1-k) = C(n-1, k)，将整个数组分隔为了 n-k 段子数组，其中每段子数组的元素都相同
    n-k 段子数组的方案数为 m * (m-1)^(n-k-1)
*/
const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }

    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};