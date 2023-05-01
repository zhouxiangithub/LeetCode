#pragma once
using namespace std;
#include <string>

class Solution {
public:
    string baseNeg2(int n) {
        string ans;
        while (n)
        {
            int remain = n % (-2);
            ans += '0' + abs(remain);
            n = remain < 0 ? n / (-2) + 1 : n / (-2);
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};