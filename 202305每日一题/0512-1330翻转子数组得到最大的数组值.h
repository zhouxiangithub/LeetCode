#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int value = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            value += abs(nums[i] - nums[i + 1]);
        }
        int mx1 = 0;
        for (int i = 1; i < n - 1; i++)
        {
            mx1 = max(mx1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1])); //翻转前半部分
            mx1 = max(mx1, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1])); //翻转后半部分
        }
        int mx2 = INT_MIN, mi2 = INT_MAX;
        for (int i = 0; i < n - 1; i++) //翻转中间部分
        {
            int x = nums[i], y = nums[i + 1];
            mx2 = max(mx2, min(x, y));
            mi2 = min(mi2, max(x, y));
        }
        return value + max(mx1, 2 * (mx2 - mi2));
    }
};