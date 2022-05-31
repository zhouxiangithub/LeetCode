#pragma once
using namespace std;
#include <vector>

//超时了
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = 1;
            for (int j = i; j < n; j++)
            {
                temp *= nums[j];
                if (temp >= k)
                {
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};

//固定右端点，移动左端点，这样就不需要每次都从索引0处开始枚举
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int temp = 1, left = 0;
        for (int right = 0; right < n; right++)
        {
            temp *= nums[right];
            while (left <= right && temp >= k)
            {
                temp /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};