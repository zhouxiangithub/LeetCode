#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long totalLose = 0;
        int res = 0;
        for (auto& trans : transactions) {
            auto [cost, cashback] = pair(trans[0], trans[1]);
            totalLose += max(cost - cashback, 0);
            res = max(res, min(cost, cashback));
        }
        return totalLose + res;
    }
};