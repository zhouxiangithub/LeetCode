#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& point : points)
        {
            int x = point[0], y = point[1];
            while (!pq.empty() && x - pq.top().second > k)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                res = max(res, x + y - pq.top().first);
            }
            pq.emplace(x - y, x);
        }
        return res;
    }
};