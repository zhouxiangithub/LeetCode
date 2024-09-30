#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    unordered_map<int, int> memo;

    int countSpecialNumbers(int n) {
        string nStr = to_string(n);
        int res = 0;
        int prod = 9;
        for (int i = 0; i < nStr.size() - 1; i++) {
            res += prod;
            prod *= 9 - i;
        }
        res += dp(0, false, nStr);
        return res;
    }

    // mask 表示前缀中使用过的数字(1使用过)
    // prefixSmaller 表示当前的前缀是否小于 n 的前缀
    int dp(int mask, bool prefixSmaller, const string& nStr) {
        if (__builtin_popcount(mask) == nStr.size()) {
            return 1;
        }
        int key = mask * 2 + (prefixSmaller ? 1 : 0);
        if (!memo.count(key)) {
            int res = 0;
            int lowerBound = mask == 0 ? 1 : 0;
            int upperBound = prefixSmaller ? 9 : nStr[__builtin_popcount(mask)] - '0';
            for (int i = lowerBound; i <= upperBound; i++) {
                if (((mask >> i) & 1) == 0) {
                    res += dp(mask | (1 << i), prefixSmaller || i < upperBound, nStr);
                }
            }
            memo[key] = res;
        }
        return memo[key];
    }
};