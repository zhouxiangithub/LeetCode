#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        int diff = *maxit - *minit;
        int ans = 1;
        for (int d = -diff; d <= diff; d++)
        {
            //f[num]��ʾ������numΪĩβԪ��,dΪ����ĵȲ����е���󳤶�
            vector<int> f(*maxit + 1, -1);
            for (int num : nums)
            {
                int prev = num - d;
                if (prev >= *minit && prev <= *maxit && f[prev] != -1)
                {
                    f[num] = max(f[num], f[prev] + 1);
                    ans = max(ans, f[num]);
                }
                f[num] = max(f[num], 1);
            }
        }
        return ans;
    }
};