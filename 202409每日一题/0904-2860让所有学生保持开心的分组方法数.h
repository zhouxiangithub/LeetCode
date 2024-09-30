#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int countWays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // 人数确定分组方案即确定
        for (int k = 0; k <= n; k++) {
            // 前 k 个元素的最大值是否小于 k
            if (k > 0 && k <= nums[k - 1]) {
                continue;
            }
            //后 n-k 个元素的最小值是否大于 k
            if (k < n && k >= nums[k]) {
                continue;
            }
            res++;
        }
        return res;
    }
};