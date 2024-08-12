#pragma once
using namespace std;
#include <vector>
#include <set>

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sx, sy;
        for (auto& point : points) {
            sx.emplace(point[0] - point[1]);
            sy.emplace(point[0] + point[1]);
        }
        int res = INT_MAX;
        for (auto& point : points) {
            sx.erase(sx.find(point[0] - point[1]));
            sy.erase(sy.find(point[0] + point[1]));
            res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));
            sx.emplace(point[0] - point[1]);
            sy.emplace(point[0] + point[1]);
        }
        return res;
    }
};