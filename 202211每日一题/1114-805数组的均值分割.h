#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <unordered_set>

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        if (n == 1)
        {
            return false;
        }

        //avgA=avgB=avgSum
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int& x : nums)
        {
            x = x * n - sum; //(减去平均值)每个数扩大n倍以防止浮点数造成的误差
        }

        unordered_set<int> left;
        for (int i = 1; i < (1 << m); i++)
        {
            int tot = 0;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    tot += nums[j];
                }
            }
            if (tot == 0)
            {
                return true;
            }
            left.emplace(tot);
        }

        int rsum = accumulate(nums.begin() + m, nums.end(), 0);
        for (int i = 1; i < (1 << (n - m)); i++)
        {
            int tot = 0;
            for (int j = m; j < n; j++)
            {
                if (i & (1 << (j - m)))
                {
                    tot += nums[j];
                }
            }
            if (tot == 0 || (rsum != tot && left.count(-tot)))
            {
                return true;
            }
        }
        return false;
    }
};