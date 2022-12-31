#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool check(vector<int>& group, vector<int>& nums, int k)
    {
        if (k + group.size() > nums.size())
        {
            return false;
        }
        for (int i = 0; i < group.size(); i++)
        {
            if (group[i] != nums[k + i])
            {
                return false;
            }
        }
        return true;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0;
        for (int k = 0; k < nums.size() && i < groups.size();)
        {
            if (check(groups[i], nums, k))
            {
                k += groups[i].size();
                i++;
            }
            else
            {
                k++;
            }
        }
        return i == groups.size();
    }
};