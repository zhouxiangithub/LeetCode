#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    //³¬Ê±ÁË
    int minMoves(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.begin() + n);
        int min = nums[0], max = nums[n - 1];
        int res = 0;
        while (min < max)
        {
            nums[n - 1] -= 1;
            res++;
            sort(nums.begin(), nums.begin() + n);
            min = nums[0];
            max = nums[n - 1];
        }
        return res;
    }

    int minMoves(vector<int>& nums)
    {
        int min = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums)
        {
            res += num - min;
        }
        return res;
    }
};