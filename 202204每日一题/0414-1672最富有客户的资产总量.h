#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int res = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += accounts[i][j];
            }
            res = max(res, sum);
        }
        return res;
    }

    int maximumWealth1(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int res = INT_MIN;
        for (auto& account : accounts)
        {
            res = max(res, accumulate(account.begin(), account.end(), 0));
        }
        return res;
    }
};