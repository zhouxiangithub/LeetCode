#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && nums[j] == nums[i])
            {
                j++;
            }
            //[i,j)
            res += i * (j - i) * (n - j);
        }
        return res;
    }
};