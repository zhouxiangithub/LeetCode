#pragma once
using namespace std;
#include <string>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int numSub(string s) {
        long long res = 0;
        int idx = 0;
        while (idx < s.length()) {
            if (s[idx] == '0') {
                idx++;
                continue;
            }

            // 每一组连续的'1'做贡献:cnt*(cnt+1)/2
            int cnt = 0;
            while (idx < s.length() && s[idx] == '1') {
                cnt++;
                idx++;
            }
            res += cnt * ((long long)cnt + 1LL) / 2;
            res %= MOD;
        }
        return res;
    }
};