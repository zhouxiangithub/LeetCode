#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        bool flag = true;
        for (int i = 0; i + 1 < n; i++)
        {
            if (flag && nums[i] == nums[i + 1])
            {
                ans++;
            }
            else
            {
                flag = !flag;
            }
        }
        return ((n - ans) & 1) ? ++ans : ans;
    }
};

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), ans = 0, idx = 0;
        while (idx < n)
        {
            int num = nums[idx];
            while (idx + 1 < n && nums[++idx] == num)
            {
                ans++;
            }
            idx++;
        }
        return ((n - ans) & 1) ? ++ans : ans;
    }
};