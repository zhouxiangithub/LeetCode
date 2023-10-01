#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        //求最大值的最小值问题
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int count = 0;
            bool visited = false;
            for (int num : nums)
            {
                if (num <= mid && !visited) 
                {
                    count++; //在最大金额为mid的情况下可以偷取的最大房屋数目
                    visited = true;
                }
                else
                {
                    visited = false;
                }
            }
            if (count >= k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};