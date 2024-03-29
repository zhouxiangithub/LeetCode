#pragma once
using namespace std;
#include <vector>

/*
    dp[i][0]表示到位置i为止使数组nums1和nums2满足严格递增并且位置i不进行交换操作的最小操作数
    dp[i][1]表示到位置i为止使数组nums1和nums2满足严格递增并且位置i进行交换操作的最小操作数
*/
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a = 0, b = 1;
        for (int i = 1; i < n; i++)
        {
            int at = a, bt = b;
            a = b = n;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                a = min(a, at);
                b = min(b, bt + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
            {
                a = min(a, bt);
                b = min(b, at + 1);
            }
        }
        return min(a, b);
    }
};