#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; j++)
            {
                while (nums[j] - nums[i] > mid)
                {
                    i++;
                }
                cnt += j - i; //右端点为j且距离小于等于mid的数对数目为j-i
            }
            if (cnt >= k)
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