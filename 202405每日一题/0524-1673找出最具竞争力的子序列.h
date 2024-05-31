#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!res.empty() && res.size() + n - (i + 1) >= k && nums[i] < res.back()) {
                res.pop_back();
            }
            res.emplace_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};