#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (i + 1 < n && nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            //在遍历的同时进行原地交换,将所有非零的元素移动到数组的头部
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};