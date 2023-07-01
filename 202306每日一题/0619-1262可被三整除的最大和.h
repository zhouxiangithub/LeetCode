#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v[3]; //ำเสý0,1,2
        for (int num : nums)
        {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int ans = 0;
        int total1 = v[1].size(), total2 = v[2].size();
        for (int cnt1 = total1 - 2; cnt1 <= total1; cnt1++)
        {
            if (cnt1 >= 0)
            {
                for (int cnt2 = total2 - 2; cnt2 <= total2; cnt2++)
                {
                    // (1*cnt1+2*cnt2)mod3=0 <==> (cnt1-cnt2)mod3=0
                    if (cnt2 >= 0 && (cnt1 - cnt2) % 3 == 0)
                    {
                        ans = max(ans, accumulate(v[1].begin(), v[1].begin() + cnt1, 0) + accumulate(v[2].begin(), v[2].begin() + cnt2, 0));
                    }
                }
            }
        }
        return ans + accumulate(v[0].begin(), v[0].end(), 0);
    }
};