#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = ((pre << 1) + nums[i]) % 5;
            res.emplace_back(pre == 0);
        }
        return res;
    }
};