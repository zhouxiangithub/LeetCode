#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();
        int right = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int left = max(right, j - k);
                right = min(n - 1, j + k) + 1;
                for (int i = left; i < right; i++) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};