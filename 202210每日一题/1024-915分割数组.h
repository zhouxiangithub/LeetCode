#pragma once
using namespace std;
#include <vector>

//两次遍历
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> minRight(n);
        minRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            minRight[i] = min(nums[i], minRight[i + 1]);
        }
        int maxLeft = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            maxLeft = max(maxLeft, nums[i]);
            if (maxLeft <= minRight[i + 1])
            {
                return i + 1;
            }
        }
        return n - 1;
    }
};

//一次遍历
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftMax = nums[0], leftPos = 0, curMax = nums[0];
        for (int i = 1; i <= n - 2; i++)
        {
            curMax = max(curMax, nums[i]);
            if (nums[i] < leftMax)
            {
                leftMax = curMax;
                leftPos = i;
            }
        }
        return leftPos + 1;
    }
};