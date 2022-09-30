#pragma once
using namespace std;
#include <vector>
#include <algorithm>

//动态规划
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0])
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - *max_element(f.begin(), f.end());
    }
};

//贪心
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1]; });
        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= right)
            {
                ans++;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};