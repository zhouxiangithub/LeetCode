#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, dp = 0, n = nums.size();
        for (int left = n - 1; left >= 0; left--)
        {
            if (nums[left] > threshold)
            {
                dp = 0;
            }
            else if (left == n - 1 || (nums[left] % 2 != nums[left + 1] % 2))
            {
                dp++;
            }
            else
            {
                dp = 1;
            }
            if (nums[left] % 2 == 0)
            {
                res = max(res, dp);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n;)
        {
            if (nums[i] > threshold || (nums[i] % 2 != 0))
            {
                i++;
                continue;
            }
            int j = i + 1;
            while (j < nums.size() && (nums[j] % 2 != nums[j - 1] % 2) && nums[j] <= threshold)
            {
                j++;
            }
            res = max(res, j - i); //(j-1)-i+1
            i = j;
        }
        return res;
    }
};