#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int help(vector<int>& hmin, vector<int>& hmax, int diff)
    {
        vector<int> h(7, 0); //每个数对diff的贡献度
        for (int i = 1; i < 7; i++)
        {
            h[6 - i] += hmin[i];
            h[i - 1] += hmax[i];
        }
        int res = 0;
        for (int j = 5; j && diff > 0; j--) //贡献度从大到小遍历保证操作数最小
        {
            int t = min((diff + j - 1) / j, h[j]); //diff/j向上取整
            res += t;
            diff -= t * j;
        }
        return res;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (6 * n < m || 6 * m < n)
        {
            return -1;
        }
        vector<int> cnt1(7, 0), cnt2(7, 0);
        int diff = 0;
        for (auto& i : nums1)
        {
            cnt1[i]++;
            diff += i;
        }
        for (auto& j : nums2)
        {
            cnt2[j]++;
            diff -= j;
        }
        if (!diff)
        {
            return 0;
        }
        if (diff > 0)
        {
            return help(cnt2, cnt1, diff);
        }
        return help(cnt1, cnt2, -diff);
    }
};