#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums)
        {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++)
        {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i)
            {
                if (occured[j])
                {
                    if (subGcd == 0)
                    {
                        subGcd = j;
                    }
                    else
                    {
                        subGcd = gcd(subGcd, j);
                    }
                    if (subGcd == i) //最大公约数i找到了
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};