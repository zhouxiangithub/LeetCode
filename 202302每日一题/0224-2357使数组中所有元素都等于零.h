#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    void subtract(vector<int>& nums, int x, int startIndex)
    {
        int n = nums.size();
        for (int i = startIndex; i < n; i++)
        {
            nums[i] -= x;
        }
    }

    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                subtract(nums, nums[i], i);
                ans++;
            }
        }
        return ans;
    }
};