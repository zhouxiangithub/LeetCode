#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += (1 - nums[right]);
            while (sum > k)
            {
                sum -= (1 - nums[left++]);
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};