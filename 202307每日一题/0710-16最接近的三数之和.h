#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        //根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target))
            {
                best = cur;
            }
        };

        for (int first = 0; first < n; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1, third = n - 1;
            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target)
                {
                    return sum;
                }
                update(sum);
                if (sum > target)
                {
                    int third_l = third - 1;
                    //移动到下一个不相等的元素
                    while (second < third_l && nums[third_l] == nums[third])
                    {
                        third_l--;
                    }
                    third = third_l;
                }
                else
                {
                    int second_r = second + 1;
                    while (second_r < third && nums[second] == nums[second_r])
                    {
                        second_r++;
                    }
                    second = second_r;
                }
            }
        }

        return best;
    }
};