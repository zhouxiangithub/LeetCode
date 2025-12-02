#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int g = 0;
        for (int num : nums) {
            if (num == 1) {
                cnt1++;
            }
            g = gcd(g, num);
        }
        if (cnt1 > 0) {
            return n - cnt1;
        }
        if (g > 1) {
            return -1;
        }

        int minLen = n; // 产生 1 的最小长度,则得到 1 的次数为: (minLen-1) + (n-1)
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen + n - 2;
    }
};