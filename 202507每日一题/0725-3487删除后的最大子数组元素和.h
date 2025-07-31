#pragma once
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> uSet;
        for (int num : nums) {
            if (num > 0) {
                uSet.emplace(num);
            }
        }
        if (uSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(uSet.begin(), uSet.end(), 0);
    }
};