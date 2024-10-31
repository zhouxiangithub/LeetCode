#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <bitset>

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return 2 * rewardValues[n - 1] - 1;
        }
        bitset<100000> f0, f1; // 一次操作前后的 dp 数组分别记为 f1 和 f0
        f0[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < rewardValues[i]) {
                f1[j] = f0[j];
                j++;
            }
            f0 |= f1 << rewardValues[i];
        }
        int res = 0;
        for (int i = 0; i < f0.size(); i++) {
            if (f0[i]) {
                res = i;
            }
        }
        return res;
    }
};