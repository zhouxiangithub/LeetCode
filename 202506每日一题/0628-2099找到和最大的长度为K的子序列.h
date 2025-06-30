#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.emplace_back(i, nums[i]);
        }
        sort(vec.begin(), vec.end(), [&](auto& v1, auto& v2) {
            return v1.second > v2.second;
            });
        sort(vec.begin(), vec.begin() + k);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].second);
        }
        return res;
    }
};