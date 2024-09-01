#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31); //dp[t] 表示高度为 t−1 根结点为 0 的满二叉树中不包含连续 1 的从根结点到叶结点的路径数量
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int pre = 0, res = 0;
        for (int i = 29; i >= 0; i--) {
            int val = 1 << i;
            if ((n & val) != 0) {
                res += dp[i + 1];
                if (pre == 1) {
                    break;
                }
                pre = 1;
            }
            else {
                pre = 0;
            }

            if (i == 0) {
                res++;
            }
        }
        return res;
    }
};