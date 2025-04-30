#pragma once
using namespace std;
#include <string>

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return calculate(to_string(finish), limit, s) - calculate(to_string(start - 1), limit, s);
    }

    // 后缀是 s 且 <=x 且满足 limit 的数字数量
    long long calculate(string x, int limit, string s) {
        if (x.length() < s.length()) {
            return 0;
        }
        if (x.length() == s.length()) {
            return x >= s;
        }

        string suffix = x.substr(x.length() - s.length(), s.length());
        long long count = 0;
        int preLen = x.length() - s.length();

        for (int i = 0; i < preLen; i++) {
            if ((x[i] - '0') > limit) {
                count += (long)pow(limit + 1, preLen - i);
                return count;
            }
            count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - i - 1);
        }
        if (suffix >= s) {
            count++;
        }
        return count;
    }
};