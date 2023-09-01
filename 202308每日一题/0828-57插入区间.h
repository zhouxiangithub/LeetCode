#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool flag = false;
        vector<vector<int>> ans;
        for (const auto& interval : intervals)
        {
            if (right < interval[0])
            {
                if (!flag)
                {
                    ans.push_back({ left,right });
                    flag = true;
                }
                ans.push_back(interval);
            }
            else if (left > interval[1])
            {
                ans.push_back(interval);
            }
            else
            {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!flag)
        {
            ans.push_back({ left,right });
        }
        return ans;
    }
};