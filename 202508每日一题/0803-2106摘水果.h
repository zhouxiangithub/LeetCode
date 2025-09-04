#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            pos[i] = fruits[i][0];
        }
        int res = 0;
        for (int x = 0; x <= k / 2; x++) {
            // 向左走x步,再向右走k-x步
            int left = startPos - x;
            int right = startPos - x + k - x;
            int start = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int end = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, sum[end] - sum[start]);
            // 向右走x步,再向左走k-x步
            right = startPos + x;
            left = startPos + x - (k - x);
            start = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            end = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, sum[end] - sum[start]);
        }
        return res;
    }
};