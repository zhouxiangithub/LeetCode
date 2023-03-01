#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, bool> cnt;
        for (int num : nums)
        {
            if (cnt.count(num))
            {
                cnt[num] = !cnt[num];
            }
            else
            {
                cnt[num] = true;
            }
            if (!cnt[num])
            {
                res++;
            }
        }
        return { res,n - 2 * res };
    }
};