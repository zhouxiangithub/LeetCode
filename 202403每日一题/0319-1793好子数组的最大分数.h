#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k - 1, right = k + 1;
        int ans = 0;
        for (int num = nums[k];;)
        {
            while (left >= 0 && nums[left] >= num)
            {
                left--;
            }
            while (right < n && nums[right] >= num)
            {
                right++;
            }
            ans = max(ans, (right - 1 - left) * num);
            if (left == -1 && right == n)
            {
                break;
            }
            num = max((left == -1 ? -1 : nums[left]), (right == n ? -1 : nums[right]));
        }
        return ans;
    }
};