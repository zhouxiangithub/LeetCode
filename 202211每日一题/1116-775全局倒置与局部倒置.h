#pragma once
using namespace std;
#include <vector>

/*
    方法一:
    一个局部倒置一定是一个全局倒置
    因此只需要检查是否存在非局部倒置,即: nums[i]>nums[j], j>i+1
    nums[i]>min(nums[i+2],nums[i+3],...,nums[n-1])

    方法二:
    不存在非局部倒置的排列的充分必要条件为;
    对于每个元素nums[i]都满足:abs(nums[i]-i)<=1
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minR = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] > minR)
            {
                return false;
            }
            minR = min(minR, nums[i + 1]);
        }
        return true;
    }
};