#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> query; //[查询,查询对应的索引]
        for (int i = 0; i < m; i++)
        {
            query.emplace_back(queries[i], i);
        }
        sort(query.begin(), query.end());

        vector<int> ans(m, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //[区间长度,右区间值]
        int i = 0;
        for (auto& [value, index] : query)
        {
            while (i < n && value >= intervals[i][0])
            {
                int a = intervals[i][0], b = intervals[i][1];
                pq.emplace(b - a + 1, b);
                i++;
            }
            while (!pq.empty() && value > pq.top().second)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};