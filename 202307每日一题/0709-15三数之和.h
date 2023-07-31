#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //枚举第一个数
        for (int first = 0; first < n; first++)
        {
            //(1)需要和上一次枚举的数不同,避免重复
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            //第三个数对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            //枚举第二个数
            for (int second = first + 1; second < n; second++)
            {
                //(2)需要和上一次枚举的数不同,避免重复
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                //需要保证第二个数的指针在第三个数的指针的左侧
                while (second<third && nums[second] + nums[third]>target)
                {
                    third--;
                }
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({ nums[first],nums[second],nums[third] });
                }
            }
        }
        return ans;
    }
};