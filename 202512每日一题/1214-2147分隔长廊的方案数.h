#pragma once
using namespace std;
#include <string>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int numberOfWays(string corridor) {
        int res = 1, cntS = 0, preIdx = -1;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                cntS++;
                if (cntS > 2 && (cntS & 1)) {
                    res = static_cast<long long>(res) * (i - preIdx) % MOD; // (i-1)-(preIdx+1)+1=i-preIdx-1¸öP£¬i-preIdx¸ö¿ÕÎ»
                }
                preIdx = i;
            }
        }
        if (cntS < 2 || cntS & 1) {
            return 0;
        }
        return res;
    }
};