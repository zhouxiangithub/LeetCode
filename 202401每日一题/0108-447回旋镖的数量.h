#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& point1 : points)
        {
            unordered_map<int, int> cnt;
            for (auto point2 : points)
            {
                int dis = (point1[0] - point2[0]) * (point1[0] - point2[0]) + (point1[1] - point2[1]) * (point1[1] - point2[1]);
                cnt[dis]++;
            }
            for (auto& [_, c] : cnt)
            {
                ans += c * (c - 1);
            }
        }
        return ans;
    }
};