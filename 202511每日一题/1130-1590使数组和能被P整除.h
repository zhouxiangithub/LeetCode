#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (int num : nums) {
            sum = (sum + num) % p;
        }
        if (sum == 0) {
            return 0;
        }
        unordered_map<int, int> valToIdx;
        int res = nums.size(), val = 0; // 不允许将整个数组都移除
        for (int i = 0; i < nums.size(); i++) {
            valToIdx[val] = i;
            val = (val + nums[i]) % p;
            if (valToIdx.count((val - sum + p) % p)) {
                res = min(res, i - valToIdx[(val - sum + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};