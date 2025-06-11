#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> arr(nums.size() + 1, 0);
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            arr[left] += 1;
            arr[right + 1] -= 1;
        }
        vector<int> count;
        int cur = 0;
        for (int a : arr) {
            cur += a;
            count.push_back(cur);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};