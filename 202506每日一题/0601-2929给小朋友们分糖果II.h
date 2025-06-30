#pragma once
using namespace std;
#include <algorithm>

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }
            ans += min(limit, n - i) - max(n - i - limit, 0) + 1;
        }
        return ans;
    }
};