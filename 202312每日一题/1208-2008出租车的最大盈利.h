#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [&](const vector<int>& r1, const vector<int>& r2)->bool {
            return r1[1] < r2[1];
            });
        int size = rides.size();
        vector<long long> dp(size + 1);
        for (int i = 0; i < size; i++)
        {
            int j = upper_bound(rides.begin(), rides.begin()+i, rides[i][0], [](int x, const vector<int>& r)->bool {
                return x < r[1];
                }) - rides.begin();
            dp[i + 1] = max(dp[i], dp[j] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
        return dp[size];
    }
};