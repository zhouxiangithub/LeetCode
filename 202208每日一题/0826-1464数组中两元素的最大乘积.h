#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = 0, secondmax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > secondmax)
            {
                secondmax = nums[i];
            }
            if (max < secondmax)
            {
                swap(max, secondmax);
            }
        }
        return (max - 1) * (secondmax - 1);
    }
};