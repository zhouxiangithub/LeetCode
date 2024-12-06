#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i <= n - k; i++) {
            bool valid = true;
            for (int j = i + 1; j <= i + k - 1; j++) {
                if (nums[j] - nums[j - 1] != 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans[i] = nums[i + k - 1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i < n; i++) {
            cnt = (i == 0 || nums[i] - nums[i - 1] != 1) ? 1 : cnt + 1;
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};