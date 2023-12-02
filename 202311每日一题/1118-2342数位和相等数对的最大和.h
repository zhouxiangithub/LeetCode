#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = -1;
        for (int num : nums)
        {
            int sum = 0, tmp = num;
            while (tmp > 0)
            {
                sum += tmp % 10;
                tmp /= 10;
            }
            auto it = mp.find(sum);
            if (it != mp.end())
            {
                res = max(res, it->second + num);
                mp[sum] = max(mp[sum], num);
            }
            else
            {
                mp[sum] = num;
            }
        }
        return res;
    }
};