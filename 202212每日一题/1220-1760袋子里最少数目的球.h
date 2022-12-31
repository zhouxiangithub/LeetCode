#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            long long ops = 0;
            for (int num : nums)
            {
                ops += (num - 1) / mid;
            }
            if (ops <= maxOperations)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};