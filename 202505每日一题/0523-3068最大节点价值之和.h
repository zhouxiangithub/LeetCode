#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> diff;
        for (auto& num : nums) {
            diff.push_back((num ^ k) - num);
        }
        sort(diff.begin(), diff.end());
        for (int i = diff.size() - 1; i > 0; i -= 2) {
            if (diff[i] + diff[i - 1] >= 0) {
                res += (diff[i] + diff[i - 1]);
            }
        }
        return res;
    }
};