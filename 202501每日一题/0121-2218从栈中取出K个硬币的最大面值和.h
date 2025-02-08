#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> f(k + 1, -1); // f[i]��ʾ����i�β������Եõ��������ֵ֮��
        f[0] = 0;
        for (const auto& pile : piles) {
            for (int i = k; i > 0; i--) {
                int value = 0;
                for (int t = 1; t <= pile.size(); t++) {
                    value += pile[t - 1];
                    if (i >= t && f[i - t] != -1) {
                        f[i] = max(f[i], f[i - t] + value);
                    }
                }
            }
        }
        return f[k];
    }
};