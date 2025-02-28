#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    // 没有选择上一个数且当前数与上一个数相同则跳过
                    if (i > 0 && ((mask >> (i - 1)) & 1) == 0 && (nums[i] == nums[i - 1])) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};