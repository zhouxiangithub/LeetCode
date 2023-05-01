#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto n : nums)
        {
            if (n % 2 == 0)
            {
                count[n]++;
            }
        }
        int res = -1, cnt = 0;
        for (auto& c : count)
        {
            if (res == -1 || c.second > cnt || (c.second == cnt && c.first < res))
            {
                res = c.first;
                cnt = c.second;
            }
        }
        return res;
    }
};