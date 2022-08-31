#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        //数x出现的次数count[x]，出现次数f的数的数目freq[f]
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            //当前数次数增加，则原先freq数减1
            if (count[nums[i]] > 0)
            {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = (maxFreq == 1) ||
                (freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1) ||
                (freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1);
            if (ok)
            {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};