#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }

        auto dp = [&]()->int {
            vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; i++) {
                for (int j = max(i + 1, n - 1 - i); j < n; j++) {
                    int best = prev[j];
                    if (j - 1 >= 0) {
                        best = max(best, prev[j - 1]);
                    }
                    if (j + 1 < n) {
                        best = max(best, prev[j + 1]);
                    }
                    curr[j] = best + fruits[i][j];
                }
                swap(prev, curr);
            }
            return prev[n - 1];
        };

        // ÓÒÉÏ
        res += dp();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(fruits[j][i], fruits[i][j]);
            }
        }

        // ×óÏÂ
        res += dp();

        return res;
    }
};