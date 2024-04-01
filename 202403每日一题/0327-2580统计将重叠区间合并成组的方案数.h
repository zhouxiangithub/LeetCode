#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    static constexpr int mod = 1e9 + 7;
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        long long res = 1;
        for (int i = 0; i < n;)
        {
            int right = ranges[i][1];
            int j = i + 1;
            while (j < n && ranges[j][0] <= right)
            {
                right = max(right, ranges[j][1]);
                j++;
            }
            res = res * 2 % mod;
            i = j;
        }
        return res;
    }
};