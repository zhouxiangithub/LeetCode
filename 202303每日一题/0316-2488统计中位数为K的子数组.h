#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    inline int sign(int num)
    {
        if (num == 0)
        {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int kIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == k)
            {
                kIndex = i;
                break;
            }
        }
        int ans = 0;
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += sign(nums[i] - k);
            if (i < kIndex)
            {
                counts[sum]++;
            }
            else
            {
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                ans += prev0 + prev1;
            }
        }
        return ans;
    }
};