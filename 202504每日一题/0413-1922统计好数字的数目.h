#pragma once
using namespace std;

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countGoodNumbers(long long n) {
        auto mul = [](int x, long long y)->int {
            int res = 1, a = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    res = (long long)res * a % mod;
                }
                a = (long long)a * a % mod;
                y /= 2;
            }
            return res;
        };

        // ����Ϊ n ���ַ����� (n+1)/2 ��ż���±� n/2 �������±�
        return (long long)mul(5, (n + 1) / 2) * mul(4, n / 2) % mod;
    }
};