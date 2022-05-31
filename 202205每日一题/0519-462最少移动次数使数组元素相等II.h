#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0, x = nums[n / 2];
        for (int i = 0; i < n; i++)
        {
            res += abs(nums[i] - x);
        }
        return res;
    }
};