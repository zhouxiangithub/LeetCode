#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        unordered_map<int, int> valToIdx;
        int res = 0, preIdx = 0;
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
            preIdx = max(preIdx, valToIdx[nums[i]]);
            res = max(res, preSum[i + 1] - preSum[preIdx]);
            valToIdx[nums[i]] = i + 1;
        }
        return res;
    }
};

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int res = 0, preSum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            preSum += nums[i];
            while (seen.count(nums[i])) {
                seen.erase(nums[j]);
                preSum -= nums[j];
                j++;
            }
            seen.emplace(nums[i]);
            res = max(res, preSum);
        }
        return res;
    }
};