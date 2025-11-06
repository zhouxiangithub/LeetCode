#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, pre = INT_MIN;
        for (int num : nums) {
            int cur = min(max(num - k, pre + 1), num + k);
            if (cur > pre) {
                res++;
                pre = cur;
            }
        }
        return res;
    }
};