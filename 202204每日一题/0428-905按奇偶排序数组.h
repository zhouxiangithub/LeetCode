#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    //两次遍历
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for (auto& num : nums)
        {
            if (num % 2 == 0)
            {
                res.emplace_back(num);
            }
        }
        for (auto& num : nums)
        {
            if (num % 2 == 1)
            {
                res.emplace_back(num);
            }
        }
        return res;
    }

    //双指针+一次遍历
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        for (auto& num : nums)
        {
            if (num % 2 == 0)
            {
                res[left++] = num;
            }
            else
            {
                res[right--] = num;
            }
        }
        return res;
    }

    //原地交换
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && nums[left] % 2 == 0)
            {
                left++;
            }
            while (left < right && nums[right] % 2 == 1)
            {
                right--;
            }
            if (left < right)
            {
                swap(nums[left++], nums[right--]);
            }
        }
        return nums;
    }
};