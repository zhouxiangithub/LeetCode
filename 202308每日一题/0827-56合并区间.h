#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (!merged.size() || left > merged.back()[1])
            {
                merged.push_back({ left,right });
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], right);
            }
        }
        return merged;
    }
};