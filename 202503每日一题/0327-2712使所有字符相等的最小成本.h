#pragma once
using namespace std;
#include <string>

class Solution {
public:
    using ll = long long;

    long long minimumCost(string s) {
        int n = s.size();
        ll res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                res += min(i + 1, n - 1 - i);
            }
        }
        return res;
    }
};