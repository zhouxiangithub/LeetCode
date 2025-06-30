#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, ele = nums[0];
        for (int& num : nums) {
            if (num - ele > k) {
                res++;
                ele = num;
            }
        }
        return res;
    }
};