#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        int res = 0;
        unordered_map<int, int> map;
        for (int num : nums)
        {
            int tmp = num, rev = 0;
            while (tmp > 0)
            {
                rev = rev * 10 + tmp % 10;
                tmp /= 10;
            }
            res = (res + map[num - rev]) % MOD;
            map[num - rev]++;
        }
        return res;
    }
};