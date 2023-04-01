#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int i : nums)
        {
            for (int j : nums)
            {
                cnt[i & j]++;
            }
        }
        int ans = 0;
        for (int k : nums)
        {
            for (int mask = 0; mask < (1 << 16); mask++)
            {
                if ((k & mask) == 0)
                {
                    ans += cnt[mask];
                }
            }
        }
        return ans;
    }
};