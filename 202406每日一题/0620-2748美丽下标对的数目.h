#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0, cnt[10]{};
        for (int j : nums) {
            for (int i = 1; i <= 9; i++) {
                if (gcd(i, j % 10) == 1) {
                    res += cnt[i];
                }
            }
            while (j >= 10) {
                j /= 10;
            }
            cnt[j]++;
        }
        return res;
    }
};